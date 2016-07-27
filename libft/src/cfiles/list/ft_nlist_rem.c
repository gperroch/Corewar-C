/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_rem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:50:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/28 10:15:18 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
** if elem, delete the node AFTER elem. Else, delete head.Use or free *content
** afterward.
*/

int	ft_nlist_rem(t_nlist *list, t_list *after, void **content,
				size_t *content_size)
{
	t_list *old;

	if (!list || list->size == 0 || (after && !after->next))
		return (-1);
	if (!after)
	{
		*content = list->head->content;
		*content_size = list->head->content_size;
		old = list->head;
		list->head = list->head->next;
		if (list->size == 1)
			list->tail = NULL;
	}
	else
	{
		*content = after->next->content;
		*content_size = after->next->content_size;
		old = after->next;
		after->next = after->next->next;
		if (!after->next)
			list->tail = after;
	}
	free(old);
	list->size--;
	return (0);
}
