/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:32:47 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:45:00 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strndup(char *s1, size_t len)
{
	char	*copy;
	int		i;

	copy = 0;
	if (s1 && len > 0)
	{
		i = 0;
		copy = ft_strnew(len);
		if (copy == NULL)
			return (0);
		while (s1[i] && len--)
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}
