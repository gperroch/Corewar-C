/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbparse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 12:58:09 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:40:30 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "fmt.h"
#include "ft_ctypes.h"

/*
** parse_nb, as parse string, begins a the %. get_flag1 is solely used for
** numbers.
*/

static void		get_flag1(char *format, t_arg *opt, t_env *e)
{
	while (format[e->iparse] && is_flag1(format[e->iparse]))
	{
		if (format[e->iparse] == '#')
			opt->prefix = 1;
		if (format[e->iparse] == '-')
			opt->justif = 'l';
		else if (format[e->iparse] == '0')
			opt->typepad = '0';
		if (opt->type == 'd' || opt->type == 'D' || opt->type == 'i')
		{
			if (format[e->iparse] == '+')
				opt->sign = '+';
			else if (format[e->iparse] == ' ' && opt->sign != '+')
				opt->sign = ' ';
		}
		e->iparse++;
	}
}

void			parse_nb(char c, char *format, t_env *e)
{
	t_arg		opt;

	init_arg(c, &opt);
	e->iparse = e->index + 1;
	while (!ft_strchr("bpdDioOuUxXcC", format[e->iparse]))
	{
		if (is_flag1(format[e->iparse]))
			get_flag1(format, &opt, e);
		if (ft_isdigit(format[e->iparse]))
			get_padding(format, &opt, e);
		if (format[e->iparse] == '.')
			get_precision(format, &opt, e);
		if (is_flag3(format[e->iparse]))
			get_flag3(format, &opt, e);
	}
	if (ft_strchr("bpdDioOuUxXcC", format[e->iparse]))
		ft_print_nb(format, &opt, e);
}
