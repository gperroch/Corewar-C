/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:50:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/28 10:13:36 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
** if elem, delete the node AFTER elem. Else, delete head.
*/

int		ft_nlist_delone(t_nlist *list, t_list *after)
{
	void	*data;
	size_t	content_size;

	if (!list)
		return (-1);
	data = NULL;
	content_size = 0;
	if (ft_nlist_rem(list, after, &data, &content_size) == 0)
	{
		if (list->destroy)
			list->destroy(data, content_size);
		return (0);
	}
	return (-1);
}
