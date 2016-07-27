/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:10:17 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:44:45 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			dst_len;

	i = 0;
	j = -1;
	dst_len = 0;
	if (size != 0)
	{
		dst_len = ft_strlen(dst);
		while (dst[i] != '\0')
			i++;
		while (src[++j] && (i + j) < size - 1)
			dst[i + j] = src[j];
		dst[i + j] = '\0';
	}
	if (dst_len + ft_strlen(src) < size)
		return (dst_len + ft_strlen(src));
	else
	{
		if (dst_len > size)
			return (ft_strlen(src) + size);
		else
			return (dst_len + ft_strlen(src));
	}
}
