/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 18:01:21 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:35:25 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void		ft_ustr(char *s)
{
	if (s)
	{
		while (*s)
		{
			if (*s >= 97 && *s <= 122)
				(*s = *s - 32);
			s++;
		}
	}
}

int			is_unsigned(char c)
{
	if (ft_strchr("cCpoOuUxXb", c))
		return (1);
	else
		return (0);
}
