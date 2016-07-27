/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itobase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 16:27:37 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:37:46 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "io.h"
#include "str.h"

/*
** Function to convert an unsigned long long number in any base from 2 to 16
*/

static void			ft_catnbr(char *s, char buf[2], unsigned long long n,
					unsigned long long base)
{
	if (n >= base)
	{
		ft_catnbr(s, buf, (n / base), base);
		ft_catnbr(s, buf, (n % base), base);
	}
	else
	{
		buf[0] = "0123456789abcdef"[n];
		ft_strcat(s, buf);
	}
}

char				*ft_itobase(unsigned long long n, unsigned long long base)
{
	char			*number;
	char			buf[2];

	if ((number = ft_strnew(66 * sizeof(char))) == NULL)
		ft_failure(NULL, "Malloc failed in ft_itobase");
	buf[1] = '\0';
	ft_catnbr(number, buf, n, base);
	return (number);
}
