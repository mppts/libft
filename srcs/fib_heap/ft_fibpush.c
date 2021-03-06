/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:18:30 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/30 22:05:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_fibpush(t_fib *fib, void *value)
{
	t_fn			*node;

	node = fnnew(value);
	if (node == NULL)
		return (FALSE);
	if (add_node_to_dictionary(fib, node) == FALSE)
	{
		fndel(&node, NULL);
		return (FALSE);
	}
	if (fib->priority == NULL)
	{
		node->left = node;
		node->right = node;
		fib->priority = node;
	}
	else
	{
		insert_node_in_rootlist(fib->priority, node);
		if (fib->cmp(fib->priority->value, node->value) == FALSE)
			fib->priority = node;
	}
	fib->n++;
	return (TRUE);
}
