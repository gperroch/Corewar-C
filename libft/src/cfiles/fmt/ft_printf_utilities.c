/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 17:49:25 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:36:28 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"
#include "str.h"

int		is_conv(char c)
{
	if (ft_strchr("sSpdDioOuUxXcCb", c) != NULL)
		return (1);
	else
		return (0);
}

int		is_flag(char c)
{
	if (ft_strchr(".#0-+ hljz", c) != NULL || ft_isdigit(c))
		return (1);
	else
		return (0);
}

int		is_flag1(char c)
{
	if (ft_strchr("0 -+#", c))
		return (1);
	else
		return (0);
}

int		is_flag3(char c)
{
	if (ft_strchr("lhjz", c))
		return (1);
	else
		return (0);
}
