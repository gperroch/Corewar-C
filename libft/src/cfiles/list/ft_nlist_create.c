/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:50:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:28:26 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

t_nlist		*ft_nlist_create(void (*destroy)(void *, size_t))
{
	t_nlist	*new;

	if (!(new = (t_nlist *)ft_memalloc(sizeof(t_nlist))))
		return (NULL);
	ft_nlist_init(new, destroy);
	return (new);
}
