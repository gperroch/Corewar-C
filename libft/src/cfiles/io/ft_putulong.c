/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:33:49 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/12/23 16:21:15 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	ft_putulong(unsigned long n)
{
	if (n >= 10)
	{
		ft_putulong(n / 10);
		ft_putulong(n % 10);
	}
	else
		ft_putchar(48 + n);
}
