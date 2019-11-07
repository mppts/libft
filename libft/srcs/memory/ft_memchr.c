/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:58 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:36:00 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	uint8_t		*ps;
	uint8_t		uc;

	ps = (uint8_t*)s;
	uc = c;
	while (n--)
		if (*ps++ == uc)
			return (ps - 1);
	return (NULL);
}
