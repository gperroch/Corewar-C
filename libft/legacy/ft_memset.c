/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:09:11 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/07 15:33:02 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr_b;

	ptr_b = (char *)b;
	if (len != 0)
	{
		while (len--)
		{
			*ptr_b = (unsigned char)c;
			ptr_b++;
		}
	}
	return (b);
}
