/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:32:41 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:45:26 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	i = 0;
	new = 0;
	if (s && f)
	{
		new = (char *)malloc((ft_strlen(s) + 1) * sizeof(*s));
		if (new == NULL)
			return (0);
		while (s[i])
		{
			new[i] = (f)(i, s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
