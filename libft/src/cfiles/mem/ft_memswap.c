/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 10:06:47 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:34:33 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mem.h"

void	ft_memswap(void *m1, void *m2, size_t size)
{
	char	*a;
	char	*b;
	char	tmp;

	if (!m1 || !m2)
		return ;
	a = (char *)m1;
	b = (char *)m2;
	while (size--)
	{
		tmp = *a;
		*a++ = *b;
		*b++ = tmp;
	}
}
