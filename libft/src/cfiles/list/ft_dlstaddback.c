/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:16:11 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:46:50 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_dlst_add_back(t_dlst *root, t_dlst *new)
{
	if (root && new)
	{
		new->prev = root->prev;
		new->next = root;
		root->prev->next = new;
		root->prev = new;
	}
}
