/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:19:35 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/03/07 10:24:43 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "strconv.h"
#include <limits.h>

static int	check_big_nb(char *s, long long nb)
{
	long long	ll;

	if (nb > 10)
		return (-2);
	ll = ft_atoll(s);
	if (ll > INT_MAX || ll < INT_MIN)
	{
		return (-3);
	}
	return (0);
}

int			ft_isstrint(char *s)
{
	long long	nb;
	char		*ptr;

	if (!s)
		return (-4);
	nb = 0;
	ptr = s;
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
		if (!ft_isdigit(*s))
			return (-1);
		nb++;
		s++;
	}
	return (check_big_nb(ptr, nb));
}
