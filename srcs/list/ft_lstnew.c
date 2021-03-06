/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:49:57 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 12:21:33 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*cp_content;

	if ((lst = (t_list*)malloc(sizeof(t_list))))
	{
		if (!(lst->next = NULL) && content)
		{
			if ((cp_content = ft_memalloc(content_size)))
			{
				lst->content = ft_memcpy(cp_content, content, content_size);
				lst->content_size = content_size;
			}
			else
				ft_memdel((void **)&lst);
		}
		else
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
	}
	return (lst);
}
