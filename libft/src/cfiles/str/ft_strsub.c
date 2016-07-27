/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:02:11 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:43:24 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	new = 0;
	i = 0;
	if (s)
	{
		new = ft_strnew(len);
		if (new == NULL)
			return (0);
		while (*s && len--)
		{
			new[i] = s[start++];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
