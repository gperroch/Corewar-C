/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:31:36 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/01/04 12:22:02 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;

	ptr_d = (char *)dst;
	ptr_s = (char *)src;
	while (n-- > 0)
	{
		*ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
	}
	return (dst);
}
