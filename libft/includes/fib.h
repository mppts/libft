/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:51:37 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 17:44:57 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIB_H
# define FIB_H

/*
** fibonacci node:
**		*ptr on right neighbor
**		*ptr on left neighbor
**		*ptr on parent node
**		*ptr on child node
**		*ptr on value
**		degree of child nodes
**		bool flag mark
*/

typedef struct		s_fn
{
	struct s_fn		*right;
	struct s_fn		*left;
	struct s_fn		*parent;
	struct s_fn		*child;
	void			*value;
	size_t			degree;
	uint8_t			mark;
}					t_fn;

t_fn				*fnnew(void *value);
void				fndel(t_fn **node, void del(void*));
void				*extract_value_from_list(t_fn **node);
t_fn				*unbind_node(t_fn *list);
t_fn				*create_rootlist(t_fn **array_nodes, size_t len);
void				insert_node_in_rootlist(t_fn *rootlist, t_fn *node);

/*
** fibonacci heap:
**		*ptr on minimum node and root list
**		number of nodes
**		potential fibonacci heap
*/

typedef struct		s_fib
{
	t_fn			*priority;
	size_t			n;
	size_t			pot;
	int				(*cmp)(void*, void*);
}					t_fib;

t_fib				*ft_fibnew(int (*cmp)(void*, void*));
void				*ft_fibpop(t_fib *fib);
int					ft_fibset(t_fib *fib, void *value);

#endif
