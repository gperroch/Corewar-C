/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:10:12 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:42:21 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	inew;

	new = 0;
	inew = 0;
	if (s1 && s2)
	{
		new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*s1));
		if (new == NULL)
			return (0);
		while (*s1)
			new[inew++] = *s1++;
		while (*s2)
			new[inew++] = *s2++;
		new[inew] = '\0';
	}
	return (new);
}
