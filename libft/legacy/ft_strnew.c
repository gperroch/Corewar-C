/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:24:38 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/05 15:56:09 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*string;
	size_t	i;

	if ((string = (char *)malloc(size + 1)))
	{
		i = 0;
		while (i < size)
		{
			string[i] = '\0';
			i++;
		}
		string[i] = '\0';
		return (string);
	}
	else
		return (NULL);
}
