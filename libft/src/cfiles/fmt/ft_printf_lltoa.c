/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lltoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 12:19:57 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:37:58 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "fmt.h"
#include "io.h"

/*
** For a negative number, the "-" is handled in put_prefix_nb
*/

static unsigned int	ft_countn(long long n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void			ft_catnbr(char *s, char buf[2], long long n)
{
	if (n < 0)
	{
		if (n <= -10)
			ft_catnbr(s, buf, -(n / 10));
		ft_catnbr(s, buf, -(n % 10));
	}
	else if (n >= 10)
	{
		ft_catnbr(s, buf, (n / 10));
		ft_catnbr(s, buf, (n % 10));
	}
	else
	{
		buf[0] = 48 + n;
		ft_strcat(s, buf);
	}
}

char				*ft_lltoa(long long n)
{
	char			*number;
	unsigned int	size_n;
	char			buf[2];

	size_n = ft_countn(n);
	buf[1] = '\0';
	if ((number = ft_strnew((size_n + 1) * sizeof(char))) == NULL)
		ft_failure(NULL, "Malloc failed in ft_lltoa");
	ft_catnbr(number, buf, n);
	return (number);
}
