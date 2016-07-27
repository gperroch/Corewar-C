/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:41:17 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:29:24 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_nlist_reverse(t_nlist *lst)
{
	t_list	*ptr;

	if (!lst)
		return ;
	lst->tail = lst->head;
	ptr = lst->head;
	ft_lstreverse(&ptr);
	lst->head = ptr;
}
