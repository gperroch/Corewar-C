/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:08:28 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:27:22 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function destroys the list but NOT the root.
*/

#include "list.h"

void	ft_dlst_clear(t_dlst *root, void (*del)(void *, size_t))
{
	t_dlst	*ptr;
	t_dlst	*to_del;

	if (!root || !del)
		return ;
	ptr = root->next;
	to_del = ptr;
	while (to_del != root)
	{
		ptr = to_del->next;
		ft_dlst_del_one(root, &to_del, del);
		to_del = ptr;
	}
}
