/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:39:33 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/04 17:09:48 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	while (n--)
	{
		a = (unsigned char *)s1;
		b = (unsigned char *)s2;
		if (*a != *b)
		{
			return (*a - *b);
		}
		s1++;
		s2++;
	}
	return (0);
}
