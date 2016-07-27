/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getflag3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 12:42:31 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:54:45 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

/*
** The function get flag 3 begins at the first "flag3" encountered in the flags,
** and ends in theory at the character DduiOoxX etc.
*/

static void	get_flag3_hh(char *format, t_arg *opt, t_env *e)
{
	if (opt->conv < L)
	{
		if (format[e->iconv] == 'h')
		{
			if (format[e->iconv + 1] == 'h' && opt->conv != H)
			{
				opt->conv = HH;
				e->iconv += 2;
			}
			else
			{
				opt->conv = H;
				e->iconv++;
			}
		}
	}
	else
	{
		while (format[e->iconv] == 'h')
			e->iconv++;
	}
}

static void	get_flag3_ll(char *format, t_arg *opt, t_env *e)
{
	if (format[e->iconv] == 'l')
	{
		if (format[e->iconv + 1] == 'l')
		{
			opt->conv = LL;
			e->iconv += 2;
		}
		else
		{
			opt->conv = L;
			e->iconv++;
		}
	}
}

static void	get_flag3_jz(char *format, t_arg *opt, t_env *e)
{
	if (format[e->iconv] == 'j')
	{
		opt->conv = J;
		e->iconv++;
	}
	else if (format[e->iconv] == 'z')
	{
		opt->conv = Z;
		e->iconv++;
	}
}

void		get_flag3(char *format, t_arg *opt, t_env *e)
{
	e->iconv = e->iparse;
	while (format[e->iconv] && is_flag3(format[e->iconv]))
	{
		get_flag3_hh(format, opt, e);
		get_flag3_ll(format, opt, e);
		get_flag3_jz(format, opt, e);
	}
	e->iparse = e->iconv;
}
