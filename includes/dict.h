/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:36:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/05 16:46:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H
# define DICT_MINSIZE 8
# define DK_SIZE 16
# define GROW_RATE(d) ((d)->mask * 3)
# define PERTURB_SHIFT 5

typedef struct		s_slot
{
	unsigned long	ix;
	unsigned long	hash;
	char			*key;
	void			*value;
}					t_slot;

typedef struct		s_dict
{
	long			fill;
	long			used;
	long			mask;
	t_slot			*table;
	t_vector		*keys;
	t_vector		*items;
}					t_dict;

t_dict				*ft_dictnew(void);
void				ft_dictdel(t_dict **dict);

#endif
