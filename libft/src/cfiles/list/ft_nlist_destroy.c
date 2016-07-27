/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:50:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/28 11:54:59 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

void	ft_nlist_destroy(t_nlist *list)
{
	void	*content;
	size_t	content_size;

	if (!list)
		return ;
	content = NULL;
	content_size = 0;
	while (list->size > 0)
	{
		if (!ft_nlist_rem(list, NULL, &content, &content_size))
		{
			if (list->destroy)
				list->destroy(content, content_size);
		}
	}
	ft_bzero(list, sizeof(t_nlist));
}
