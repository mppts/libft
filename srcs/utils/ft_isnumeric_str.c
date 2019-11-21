/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:12:56 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/19 21:15:30 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumeric_str(const char *str, int is_spaces)
{
	char	*s;

	s = (char*)str;
	if (is_spaces == TRUE)
		while (ft_isspace(*s))
			s++;
	while (ft_isdigit(*s))
		s++;
	if (is_spaces == TRUE)
		while (ft_isspace(*s))
			s++;
	return (*s == '\0');
}
