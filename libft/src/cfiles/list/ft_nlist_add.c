/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:50:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/28 10:14:37 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

/*
** if element, insert AFTER element. Else, inset after head.
*/

int	ft_nlist_add(t_nlist *list, t_list *after, t_list *new)
{
	if (!list || !new)
		return (-1);
	if (!after)
	{
		if (list->size == 0)
			list->tail = new;
		new->next = list->head;
		list->head = new;
	}
	else
	{
		if (!after->next)
			list->tail = new;
		new->next = after->next;
		after->next = new;
	}
	list->size++;
	return (0);
}
