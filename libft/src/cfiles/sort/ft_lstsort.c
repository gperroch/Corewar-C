/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 17:48:13 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:46:00 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mergesort for linked list. Add a function pointer cmp.
*/

#include "list.h"

static void		splitmiddle(t_list *data, t_list **front, t_list **middle)
{
	t_list	*fast;
	t_list	*slow;

	slow = data;
	fast = data->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = data;
	*middle = slow->next;
	slow->next = NULL;
}

static t_list	*sortedmerge(t_list *front, t_list *middle, int (*cmp)())
{
	t_list	*result;

	result = NULL;
	if (!front)
		return (middle);
	if (!middle)
		return (front);
	if (cmp(front->content, middle->content) < 0)
	{
		result = front;
		result->next = sortedmerge(front->next, middle, cmp);
	}
	else
	{
		result = middle;
		result->next = sortedmerge(front, middle->next, cmp);
	}
	return (result);
}

void			ft_lstsort(t_list **data, int (*cmp)())
{
	t_list	*ptrdata;
	t_list	*front;
	t_list	*middle;

	ptrdata = *data;
	if (ptrdata == NULL || ptrdata->next == NULL)
		return ;
	splitmiddle(ptrdata, &front, &middle);
	ft_lstsort(&front, cmp);
	ft_lstsort(&middle, cmp);
	*data = sortedmerge(front, middle, cmp);
}
