/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 16:40:22 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:39:58 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "fmt.h"

static long long	get_unb(char c, t_arg *opt, t_env *e)
{
	long long	ret;

	if ((ft_strchr("ouxXb", c) && opt->conv == HH)
		|| ((c == 'c') && opt->conv != L))
		ret = (long long)(unsigned char)va_arg(e->ap, int);
	if (ft_strchr("ouxXb", c) && opt->conv == H)
		ret = (long long)(unsigned short)va_arg(e->ap, int);
	if (ft_strchr("ouxXb", c) && opt->conv == NOPE)
		ret = (long long)(unsigned int)va_arg(e->ap, int);
	if (ft_strchr("oOuUxXb", c) && opt->conv == L)
		ret = (long long)va_arg(e->ap, long);
	if (c == 'p')
		ret = (long long)va_arg(e->ap, void *);
	if (ft_strchr("oOuUxXb", c)
		&& (opt->conv == LL || opt->conv == J || opt->conv == Z))
		ret = va_arg(e->ap, long long);
	return (ret);
}

long long			get_nb(char c, t_arg *opt, t_env *e)
{
	long long	ret;

	opt->is_u = is_unsigned(c);
	if (opt->is_u)
		return (ret = get_unb(c, opt, e));
	if ((ft_strchr("di", c) && opt->conv == HH))
		ret = (long long)(char)va_arg(e->ap, int);
	if (ft_strchr("di", c) && opt->conv == H)
		ret = (long long)(short)va_arg(e->ap, int);
	if (ft_strchr("di", c) && opt->conv == NOPE)
		ret = (long long)(int)va_arg(e->ap, int);
	if (ft_strchr("dDi", c) && opt->conv == L)
		ret = (long long)va_arg(e->ap, long);
	if (ft_strchr("dDi", c)
		&& (opt->conv == LL || opt->conv == J || opt->conv == Z))
		ret = va_arg(e->ap, long long);
	return (ret);
}

static void			get_size_number_string(long long nb, t_arg *opt, char **s)
{
	if (opt->is_u)
		*s = ft_itobase((unsigned long long)nb, (unsigned long long)opt->base);
	else
		*s = ft_lltoa((long long)nb);
}

int					get_size_number(long long nb, t_arg *opt,
					t_env *e, char **s)
{
	int		ret;

	ret = 0;
	if (!opt->is_u && nb < 0)
	{
		opt->sign = '-';
		ret++;
	}
	if ((!opt->is_u && nb > 0 && ft_strchr("dDi", opt->type) && opt->sign)
		|| (ft_strchr("oO", opt->type) && (nb != 0) && opt->prefix))
		ret++;
	if ((ft_strchr("xX", opt->type) && (nb != 0) && opt->prefix)
		|| opt->type == 'p')
		ret += 2;
	if (opt->type == 'C' || (opt->type == 'c' && opt->conv == L))
	{
		*s = get_wc((wchar_t)va_arg(e->ap, wint_t), opt);
		return (opt->sizearg);
	}
	else
		get_size_number_string(nb, opt, s);
	ret += ft_strlen(*s);
	if (opt->prec - (int)ft_strlen(*s) > 0)
		ret += opt->prec - (int)ft_strlen(*s);
	return (ret);
}
