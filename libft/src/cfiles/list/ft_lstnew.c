/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:05:10 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:29:15 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

/*
** to access content, do (type_of_content *)ptr->content.
** for a char * : ((char *)ptr->content).
** for a struct : ((yourstruct *)ptr->content)->field
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = 0;
	if (content_size)
	{
		if (content)
		{
			if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
				return (0);
			if ((new->content = ft_memalloc(content_size)) == NULL)
				return (0);
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
			new->next = NULL;
		}
		else
		{
			if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
				return (0);
			new->content = NULL;
			new->content_size = 0;
			new->next = NULL;
		}
	}
	return (new);
}
