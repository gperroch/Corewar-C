/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:50:25 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/05 10:28:34 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static char	*ft_strnstr_err(const char *s1, const char *s2)
{
	if (!*s2)
		return ((char *)s1);
	else
		return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if ((!*s2) || (!*s1))
		return (ft_strnstr_err(s1, s2));
	while ((s1[i] != '\0') && i < n)
	{
		if (s1[i] == s2[j])
		{
			while ((s2[j] == s1[i + j]) && (i + j < n))
			{
				j++;
				if (!s2[j])
					return ((char *)(s1 + i));
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
