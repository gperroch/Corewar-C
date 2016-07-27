/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:55:35 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/03/04 17:11:20 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"

int		ft_isstrfloat(char *s)
{
	int			punkt;

	if (!s)
		return (-4);
	punkt = 0;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		s++;
	while (*s && *s == '0')
		s++;
	if (!*s)
		return (-1);
	while (*s)
	{
		if (*s != '.' && !ft_isdigit(*s))
			return (-1);
		if (*s == '.')
			punkt++;
		s++;
	}
	if (punkt > 1)
		return (-1);
	return (0);
}
