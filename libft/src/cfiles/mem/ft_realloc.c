/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:52:34 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:02:15 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "stdlib.h"

/*
** clumsy realloc func that imitates the behaviour of the official Linux
** realloc func. Not as efficient as the original one, the latter should be
** used if authorized.
*/

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void	*cpy;

	if (!ptr)
		return (malloc(size));
	else if (!size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!(cpy = malloc(size)))
		return (NULL);
	ft_memcpy(cpy, ptr, MEM_MIN(old, size));
	free(ptr);
	return (cpy);
}
