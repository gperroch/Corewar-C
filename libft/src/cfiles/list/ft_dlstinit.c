/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 09:27:12 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:27:46 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

t_dlst	*ft_dlst_init(void const *content, size_t content_size)
{
	t_dlst	*root;

	root = 0;
	if (content_size)
	{
		if (!(root = (t_dlst *)ft_memalloc(sizeof(t_dlst))))
			return (0);
		if ((root->content = ft_memalloc(content_size)) == NULL)
			return (0);
		ft_memcpy(root->content, content, content_size);
		root->content_size = content_size;
		root->next = root;
		root->prev = root;
	}
	else
	{
		if (!(root = (t_dlst *)ft_memalloc(sizeof(t_dlst))))
			return (0);
		root->content = NULL;
		root->content_size = 0;
		root->next = root;
		root->prev = root;
	}
	return (root);
}
