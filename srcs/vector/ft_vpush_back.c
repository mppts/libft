/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:32:17 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/02 15:00:34 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_vpush_back(t_vector *v, void *val, long val_size)
{
	long	old_size;

	if (v == NULL || val == NULL || val_size == 0)
		return (FALSE);
	old_size = v->size;
	if (val_size > ft_vunused_size(v))
		while (old_size + val_size > v->size)
			if (ft_vresize(v, v->size * EXPAND) == FALSE)
				return (FALSE);
	ft_memcpy(v->con + v->head * v->type_size, val, val_size);
	v->head += val_size / v->type_size;
	return (TRUE);
}
