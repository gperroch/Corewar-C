/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:45:23 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:29:05 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*p_new;
	t_list	*p_temp;

	new = 0;
	if (lst && f)
	{
		if ((p_new = (f)(lst)) == 0)
			return (0);
		if ((new = ft_lstnew(p_new->content, p_new->content_size)) == 0)
			return (0);
		p_temp = new;
		while (lst->next)
		{
			lst = lst->next;
			if ((p_new = (f)(lst)) == 0)
				return (0);
			p_temp->next = ft_lstnew(p_new->content, p_new->content_size);
			if (p_temp->next == 0)
				return (0);
			p_temp = p_temp->next;
		}
	}
	return (new);
}
