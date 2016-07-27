/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:57:28 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:27:29 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

void	ft_dlst_del_one(t_dlst *root, t_dlst **to_del,
		void (*del)(void *, size_t))
{
	if (root && *to_del && (*to_del != root))
	{
		(*to_del)->prev->next = (*to_del)->next;
		(*to_del)->next->prev = (*to_del)->prev;
		del((*to_del)->content, (*to_del)->content_size);
		ft_memdel((void **)to_del);
	}
}
