/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 19:04:29 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 10:08:10 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "fmt.h"

/*
** get_args begins at a %
*/

static void				get_args(char *format, t_env *e)
{
	char	*ptr;
	int		i;

	ptr = format;
	i = e->index + 1;
	while (ptr[i] && is_flag(ptr[i]))
		i++;
	if (ptr[i] == 0)
	{
		e->index = i;
		return ;
	}
	if (!(is_conv(ptr[i])))
	{
		ft_putchar(ptr[i]);
		e->count++;
		e->index = i + 1;
		return ;
	}
	else if (ptr[i] == 's' || ptr[i] == 'S')
		parse_string(ptr[i], format, e);
	else
		parse_nb(ptr[i], format, e);
}

void					init_arg(char c, t_arg *opt)
{
	opt->type = c;
	opt->padding = 0;
	opt->justif = 'r';
	opt->prec = 0;
	opt->is_prec = 0;
	opt->sizearg = 0;
	opt->typepad = ' ';
	opt->prefix = 0;
	opt->sign = 0;
	opt->is_u = 0;
	if (c == 'o' || c == 'O')
		opt->base = 8;
	else if (c == 'x' || c == 'X' || c == 'p')
		opt->base = 16;
	else if (c == 'b')
		opt->base = 2;
	else
		opt->base = 10;
	opt->sign = 0;
	if (c == 'S' || c == 'D' || c == 'O' || c == 'U' || c == 'C')
		opt->conv = L;
	else
		opt->conv = NOPE;
}

static void				init_env(t_env *e)
{
	e->count = 0;
	e->index = 0;
	e->iparse = 0;
	e->ipadding = 0;
	e->iprec = 0;
	e->iconv = 0;
}

static void				write_percent(t_env *e)
{
	ft_putchar('%');
	e->count++;
	e->index += 2;
}

int						ft_printf(const char *format, ...)
{
	t_env	e;

	if (format == NULL)
		return (0);
	init_env(&e);
	va_start(e.ap, format);
	while (format[e.index])
	{
		if (format[e.index] == '%')
		{
			if (format[e.index + 1] == '%')
				write_percent(&e);
			else
				get_args((char *)format, &e);
		}
		else
		{
			ft_putchar(format[e.index]);
			e.count++;
			e.index++;
		}
	}
	va_end(e.ap);
	return (e.count);
}
