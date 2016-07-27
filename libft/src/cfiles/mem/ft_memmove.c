/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:31:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:17:19 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dst;
	char	*ptr_src;

	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
	{
		ptr_dst = (char *)dst;
		ptr_src = (char *)src;
		while (len--)
			ptr_dst[len] = ptr_src[len];
	}
	return (void *)(dst);
}
