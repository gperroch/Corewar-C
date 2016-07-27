/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:19:28 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:46:54 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp_next;

	if (*alst && del)
	{
		temp = *alst;
		while (temp != NULL)
		{
			temp_next = temp->next;
			del((temp)->content, (temp)->content_size);
			free(temp);
			temp = temp_next;
		}
		*alst = NULL;
	}
}
