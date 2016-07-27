/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_raw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:05:10 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/02/24 10:59:53 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

/*
** Raw insertion : content of content is not copied but the address is assigned
** to content. Handle deletion of data with care.
*/

t_list	*ft_lstnew_raw(void const *content, size_t content_size)
{
	t_list	*ret;

	if (!(ret = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	ret->content = (void *)content;
	ret->content_size = content_size;
	return (ret);
}
