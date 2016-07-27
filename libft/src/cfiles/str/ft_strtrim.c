/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:37:39 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:45:10 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "str.h"

static	int	ft_spacetoend(const char *s)
{
	while (*s && ft_isspace(*s))
	{
		if (*(s + 1) == '\0')
			return (1);
		s++;
	}
	return (0);
}

static void	init_strtrim(char **s1, unsigned int *s2, char **s3)
{
	*s1 = 0;
	*s2 = 0;
	*s3 = 0;
}

char		*ft_strtrim(char const *s)
{
	char			*new;
	char			*ptr_new;
	const char		*ptr_firstchr;
	unsigned int	size_trim;

	init_strtrim(&new, &size_trim, &ptr_new);
	if (s)
	{
		while (ft_isspace(*s))
			s++;
		if (!*s)
			return (0);
		ptr_firstchr = s;
		while (*s && !(ft_spacetoend(s++)))
			size_trim++;
		new = ft_strnew(size_trim);
		if (new == NULL)
			return (0);
		ptr_new = new;
		while (size_trim--)
			*new++ = *ptr_firstchr++;
		*new = '\0';
	}
	return (ptr_new);
}
