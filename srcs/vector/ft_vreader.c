/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vreader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:01:16 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 00:45:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vreader(t_vector *v, int fd, int buff_size)
{
	long			data_size;
	long			offset;
	int				read_bytes;

	if (ft_vunused_size(v) <= buff_size)
	{
		data_size = (long)v->con - (long)v->const_con;
		v->head -= data_size;
		v->iter -= data_size;
		ft_memmove((void*)v->const_con, v->con, v->head);
		v->con = (void*)v->const_con;
		if (ft_vunused_size(v) <= buff_size)
			if (ft_vresize(v, (v->size + buff_size) * 2) == FALSE)
				return (-1);
	}
	offset = v->con - v->const_con;
	read_bytes = read(fd, v->con + v->head - offset, buff_size);
	if (read_bytes > 0)
		v->head += read_bytes;
	return (read_bytes);
}
