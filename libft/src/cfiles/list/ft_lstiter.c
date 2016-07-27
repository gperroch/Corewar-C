/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:32:20 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:28:44 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*ptr_lst;

	if (lst && f)
	{
		ptr_lst = lst;
		while (ptr_lst)
		{
			(f)(ptr_lst);
			ptr_lst = ptr_lst->next;
		}
	}
}
