/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:30:53 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:41:48 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			new[i] = (f)(s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
