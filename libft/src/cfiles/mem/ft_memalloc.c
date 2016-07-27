/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:43:27 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/08 20:54:58 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mem.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	if (size != 0 && (memory = malloc(size)))
	{
		ft_bzero(memory, size);
		return (memory);
	}
	else
		return (NULL);
}
