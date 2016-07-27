/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas-42 <thomas-42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:55:39 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/02/29 14:17:53 by thomas-42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
** merge two nlists into one new.
*/

static int	copy_list(t_nlist *new, const t_nlist *old)
{
	new->head = old->head;
	new->tail = old->tail;
	new->destroy = old->destroy;
	new->size = old->size;
	return (0);
}

int			ft_nlist_merge(t_nlist *new, const t_nlist *a, const t_nlist *b)
{
	if (!new)
		return (-1);
	if ((!a || a->size == 0) && b)
		return (copy_list(new, b));
	else if ((!b || b->size == 0) && a)
		return (copy_list(new, a));
	new->destroy = a->destroy;
	new->head = a->head;
	new->tail = a->tail;
	if (new->tail)
		new->tail->next = b->head;
	new->tail = b->tail;
	new->size = a->size + b->size;
	return (0);
}
