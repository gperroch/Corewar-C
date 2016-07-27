/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:19:31 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:27:37 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

/*
** This func destroy THE WHOLE list
*/

void	ft_dlst_destroy(t_dlst *root, void (*del)(void *, size_t))
{
	ft_dlst_clear(root, del);
	if (root->content_size && root->content)
		del(root->content, root->content_size);
	ft_memdel((void **)&root);
}
