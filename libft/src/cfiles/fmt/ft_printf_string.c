/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 11:15:26 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:37:02 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "fmt.h"
#include "str.h"

static void		ft_putnstr(char *s, int i)
{
	if (s)
	{
		while (i > 0 && *s != '\0')
		{
			ft_putchar((char)*s);
			s++;
			i--;
		}
	}
}

void			ft_printstr(t_env *e, t_arg *opt)
{
	char			*s;
	int				i;
	int				is_null;

	i = 0;
	is_null = 0;
	s = 0;
	s = va_arg(e->ap, char *);
	if (!s)
	{
		s = get_null_string(opt, e);
		is_null = 1;
	}
	else
		opt->sizearg = get_size_string(s, e, opt);
	i = opt->padding - opt->sizearg > 0 ? opt->padding - opt->sizearg + 1 : 1;
	put_padding_left(i, e, opt);
	if (opt->is_prec)
		ft_putnstr(s, opt->prec);
	else
		ft_putstr(s);
	put_padding_right(i, e, opt);
	if (is_null)
		ft_strdel(&s);
}
