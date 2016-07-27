/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:02:04 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/03/04 15:35:14 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"

static void		get_double(double *ret, char *s)
{
	int		ex;

	ex = 0;
	while (*s && ft_isdigit(*s))
	{
		*ret = *ret * 10.0 + (*s - '0');
		s++;
	}
	if (*s == '.')
	{
		s++;
		while (*s && ft_isdigit(*s))
		{
			*ret = *ret * 10.0 + (*s - '0');
			s++;
			ex--;
		}
	}
	while (ex < 0)
	{
		*ret = *ret * 0.1;
		ex++;
	}
}

double			ft_atof(char *s)
{
	double	ret;
	double	sign;

	if (!s)
		return (0.0);
	ret = 0.0;
	sign = 1.0;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		sign = -1.0;
		s++;
	}
	else if (*s == '+')
		s++;
	else if (!*s || !ft_isdigit(*s))
		return (0.0);
	get_double(&ret, s);
	return (ret * sign);
}
