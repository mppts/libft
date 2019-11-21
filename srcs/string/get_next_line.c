/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:39:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 04:02:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Vector structure used in GNL:
** ............................................................................
** data->const_con - *ptr to the beginning of the vector
** data->con - *ptr to the current starting position of the data in the vector
** data->head - number of bytes from CONST_CON to the end of the read data
** data->iter - number of examined bytes for the presence of '\n' from the
** 						beginning of the vector to the last investigated byte
** data->type_size - size of data units in bytes
** data->size - memory size of the whole vector
*/

static int			initialize_elements(int fd, \
										char **line, \
										t_dict **dict, \
										t_vector **data)
{
	char			*key;
	int				state;

	*line = NULL;
	state = TRUE;
	if (*dict == NULL)
		*dict = ft_dictnew(GNL_INIT_DICT_SIZE);
	if (*dict == NULL)
		return (FALSE);
	key = ft_itoa_base(fd, 16);
	if (key == NULL)
		return (FALSE);
	*data = ft_dictget(*dict, key);
	if (*data == NULL)
	{
		*data = ft_vnew(GNL_INIT_VEC_SIZE, sizeof(char));
		if (*data == NULL || ft_dictset(*dict, key, *data) == FALSE)
			state = FALSE;
		else
			(*data)->iter = 0;
	}
	ft_memdel((void**)&key);
	return (state);
}

static size_t		set_data_inline(t_vector *data, char **line)
{
	size_t			length;
	char			*ptr_nl;
	char			*begin;

	if (data->head == 0)
		return (0);
	begin = ((char*)data->const_con) + data->iter;
	ptr_nl = (char*)ft_memchr(begin, '\n', data->head - data->iter + 1);
	if (ptr_nl == NULL)
	{
		data->iter = data->head;
		return (0);
	}
	data->iter = (long)ptr_nl - (long)data->const_con + 1;
	length = (size_t)ptr_nl - (size_t)data->con;
	*line = ft_strnew(length);
	if (*line)
	{
		ft_memcpy(*line, data->con, length);
		data->con += length + 1;
	}
	length |= (*line == NULL ? MASK_ERROR : MASK_ACTIVE);
	return (length);
}

static size_t		update_buffer_status(int fd, t_vector *data)
{
	char			*ptr_head;
	long			read_bytes;
	int				state;

	read_bytes = 0;
	while (read_bytes < MIN_READ_BYTES)
	{
		state = ft_vreader(data, fd, BUFF_SIZE);
		ptr_head = ((char*)data->const_con) + data->head;
		if (state == -1)
			return (MASK_ERROR);
		if (state == 0)
		{
			if (((long)ptr_head - (long)data->con) < 1)
				return (0);
			*ptr_head = '\n';
			return (MASK_ACTIVE);
		}
		read_bytes += state;
		*ptr_head = '\0';
	}
	return (read_bytes);
}

static int			del_buffer_indict(int fd, \
									t_dict **dict, \
									t_vector **data)
{
	char			*key;
	int				state;

	key = ft_itoa_base(fd, 16);
	if (key == NULL)
		return (FALSE);
	ft_vdel(data);
	state = ft_dictunset(*dict, key, NULL);
	ft_memdel((void**)&key);
	if ((*dict)->used == 0)
		ft_dictdel(dict, NULL);
	return (state);
}

int					get_next_line(const int fd, char **line)
{
	static t_dict	*dict = NULL;
	t_vector		*data;
	size_t			dkix;

	if (fd < MIN_FD || BUFF_SIZE < MIN_BUFF_SIZE || line == NULL)
		return (-1);
	if (initialize_elements(fd, line, &dict, &data) == FALSE)
		return (-1);
	while (TRUE)
	{
		dkix = set_data_inline(data, line);
		if (DKIX_ACTIVE(dkix))
			return ((int)(DKIX(dkix)));
		if (DKIX_ERROR(dkix))
			return (-1);
		dkix = update_buffer_status(fd, data);
		if (DKIX_ERROR(dkix))
			return (-1);
		if (DKIX_EMPTY(dkix))
			return (del_buffer_indict(fd, &dict, &data) == TRUE ? 0 : -1);
	}
}
