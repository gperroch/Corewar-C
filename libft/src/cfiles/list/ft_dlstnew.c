/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 14:07:26 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:27:52 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "list.h"

t_dlst	*ft_dlst_new(void const *content, size_t content_size)
{
	t_dlst	*ret;

	ret = 0;
	if (content_size)
	{
		if (!(ret = (t_dlst *)ft_memalloc(sizeof(t_dlst))))
			return (0);
		if ((ret->content = ft_memalloc(content_size)) == NULL)
			return (0);
		ft_memcpy(ret->content, content, content_size);
		ret->content_size = content_size;
		ret->next = NULL;
		ret->prev = NULL;
	}
	else
	{
		if (!(ret = (t_dlst *)ft_memalloc(sizeof(t_dlst))))
			return (0);
		ret->content = NULL;
		ret->content_size = 0;
		ret->next = NULL;
		ret->prev = NULL;
	}
	return (ret);
}
