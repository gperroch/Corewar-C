/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 10:59:58 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:40:10 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "io.h"
#include "fmt.h"

static void		put_prefix_hexoct(long long nb, t_arg *opt, t_env *e, char *s)
{
	if ((ft_strchr("xX", opt->type) && opt->prefix) || opt->type == 'p')
	{
		if (opt->type == 'X' && nb != 0)
			ft_putstr("0X");
		else if ((opt->type == 'x' && nb != 0) || opt->type == 'p')
			ft_putstr("0x");
	}
	if (ft_strchr("oO", opt->type) && opt->prefix)
	{
		if (opt->prec <= (int)ft_strlen(s) && nb != 0)
			ft_putchar('0');
		else
		{
			if (nb > 0)
				e->count--;
		}
	}
}

static void		put_prefix_nb(long long nb, t_arg *opt, t_env *e, char *s)
{
	if (!opt->is_u && ft_strchr("dDi", opt->type))
	{
		if (nb < 0)
			ft_putchar('-');
		else if (nb >= 0 && opt->sign)
		{
			ft_putchar(opt->sign);
			if (nb == 0)
				e->count++;
		}
	}
	else
		put_prefix_hexoct(nb, opt, e, s);
}

static void		put_prec_nb(char *s, t_env *e, t_arg *opt)
{
	int	i;
	int	size;

	if ((opt->type == 'c' || opt->type == 'C') && opt->typepad != '0')
		return ;
	if ((!opt->is_prec && opt->typepad == '0' && opt->padding > opt->sizearg
		&& opt->justif == 'r')
		|| (opt->is_prec && opt->typepad == '0' && ft_strchr("cC", opt->type)))
		i = opt->padding - opt->sizearg;
	else
	{
		if (opt->type == 'c' || opt->type == 'C')
			size = 1;
		else
			size = ft_strlen(s);
		i = opt->prec - size;
	}
	while (i > 0)
	{
		ft_putchar('0');
		if ((opt->typepad == '0' && !opt->is_prec) || (opt->is_prec
			&& opt->typepad == '0' && ft_strchr("cC", opt->type)))
			e->count++;
		i--;
	}
}

void			ft_print_nb(char *format, t_arg *opt, t_env *e)
{
	long long	nb;
	char		*s;

	s = 0;
	nb = get_nb(format[e->iparse], opt, e);
	if (opt->type == 'c' && opt->conv != L)
		opt->sizearg = 1;
	else
		opt->sizearg = get_size_number(nb, opt, e, &s);
	put_padding_nb_left(e, opt);
	put_prefix_nb(nb, opt, e, s);
	put_prec_nb(s, e, opt);
	if (opt->type == 'X')
		ft_ustr(s);
	if (opt->type == 'c' && opt->conv != L)
		ft_putchar((char)nb);
	else if ((opt->type == 'C' && ft_strlen(s) == 0)
		|| (opt->type == 'c' && opt->conv == L && ft_strlen(s) == 0))
		ft_putchar('\0');
	else
		ft_putstr(s);
	e->count += opt->sizearg;
	put_padding_nb_right(e, opt);
	e->index = e->iparse + 1;
	ft_strdel(&s);
}
