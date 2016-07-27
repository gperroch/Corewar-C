/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:49:24 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:27:13 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_dlst_add_front(t_dlst *root, t_dlst *new)
{
	if (root && new)
	{
		new->prev = root;
		new->next = root->next;
		root->next->prev = new;
		root->next = new;
	}
}
