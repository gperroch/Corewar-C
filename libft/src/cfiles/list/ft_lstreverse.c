/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:41:17 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:29:24 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstreverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*previous;
	t_list	*next;

	if (!begin_list || !*begin_list)
		return ;
	previous = 0;
	tmp = *begin_list;
	while (tmp != 0)
	{
		next = tmp->next;
		tmp->next = previous;
		previous = tmp;
		tmp = next;
	}
	*begin_list = previous;
}
