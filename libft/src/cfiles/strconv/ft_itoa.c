/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:34:11 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:41:08 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static unsigned int	ft_countn(int n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void			ft_catnbr(char *s, char buf[2], int n)
{
	if (n < 0)
	{
		ft_strcat(s, "-");
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

char				*ft_itoa(int n)
{
	char			*number;
	unsigned int	size_n;
	char			buf[2];

	size_n = ft_countn(n);
	buf[1] = '\0';
	if ((number = ft_strnew(size_n)) == NULL)
		return (0);
	ft_catnbr(number, buf, n);
	return (number);
}
