/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 10:27:42 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:39:44 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "fmt.h"
#include "io.h"
#include "ft_ctypes.h"

/*
** parse_string begins at the %
*/

static void	get_flag1_string(char *format, t_arg *opt, t_env *e)
{
	if (format[e->iparse] == '-')
		opt->justif = 'l';
	else if (format[e->iparse] == '0')
		opt->typepad = '0';
	e->iparse++;
}

void		parse_string(char c, char *format, t_env *e)
{
	t_arg		opt;

	init_arg(c, &opt);
	e->iparse = e->index + 1;
	while (format[e->iparse] && is_flag1(format[e->iparse]))
		get_flag1_string(format, &opt, e);
	if (ft_isdigit(format[e->iparse]))
		get_padding(format, &opt, e);
	if (format[e->iparse] == '.')
		get_precision(format, &opt, e);
	while (format[e->iparse] && is_flag3(format[e->iparse]))
	{
		if (format[e->iparse] == 'l')
			opt.conv = L;
		e->iparse++;
	}
	if (format[e->iparse] == 's' && opt.conv != L)
		ft_printstr(e, &opt);
	else
		ft_printwstr(e, &opt);
	e->index = e->iparse + 1;
}

char		*get_null_string(t_arg *opt, t_env *e)
{
	char	*null;

	if ((null = ft_strnew(7 * sizeof(char))) == NULL)
		ft_failure(NULL, "Malloc failed");
	ft_strcpy(null, "(null)");
	opt->sizearg = get_size_string(null, e, opt);
	return (null);
}

int			get_size_string(char *s, t_env *e, t_arg *opt)
{
	if (opt->is_prec == 0 || opt->prec >= (int)ft_strlen(s))
	{
		e->count += ft_strlen(s);
		return (ft_strlen(s));
	}
	else
	{
		e->count = e->count + opt->prec;
		return (opt->prec);
	}
}
