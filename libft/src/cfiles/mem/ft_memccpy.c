/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:09:42 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/06 11:16:37 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(char *)dst = *(char *)src;
		if ((*(char *)src) == (unsigned char)c)
		{
			*(char *)dst = (unsigned char)c;
			dst++;
			return (dst);
		}
		dst++;
		src++;
	}
	return (0);
}
