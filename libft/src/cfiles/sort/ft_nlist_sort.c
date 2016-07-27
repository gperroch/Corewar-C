/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 17:48:13 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/28 10:19:46 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "sort.h"

void	ft_nlist_sort(t_nlist *lst, int (*cmp)())
{
	if (!lst || !cmp)
		return ;
	ft_lstsort(&lst->head, cmp);
	lst->tail = ft_lstlast(lst->head);
}
