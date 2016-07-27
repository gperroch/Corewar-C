/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:16:05 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/07 17:30:13 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*string;
	const unsigned char	*a;

	a = s;
	if (n)
	{
		while (n--)
		{
			string = (unsigned char *)a;
			if (*string == (unsigned char)c)
				return ((void *)(a));
			a++;
		}
	}
	return (0);
}
