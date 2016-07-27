/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:06:36 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:45:38 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

static int	countwords(char const *str, char c)
{
	int i;
	int count;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	ft_sizeword(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (s == 0)
		return (0);
	split = (char**)malloc((countwords(s, c) + 1) * sizeof(char**));
	if (split == 0)
		return (0);
	while (s[++i])
	{
		if (s[i] != c)
		{
			split[j] = ft_strnew(ft_sizeword(&s[i], c));
			if (split[j] == 0)
				return (0);
			ft_strncpy(split[j], &s[i], ft_sizeword(&s[i], c));
			j++;
			i += ft_sizeword(&s[i], c) - 1;
		}
	}
	split[j] = 0;
	return (split);
}
