/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcurr_con.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:07:48 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/02 16:07:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_vcurr_con(t_vector *v)
{
	if (v->iter > -1 && v->iter < v->head + 1)
		return (v->con + v->iter * v->type_size);
	return (NULL);
}
