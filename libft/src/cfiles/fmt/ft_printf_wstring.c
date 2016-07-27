/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wstring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/21 16:18:55 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:37:20 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "fmt.h"
#include "str.h"

static	char	*init_ret(wchar_t *wstring)
{
	int		i;
	char	*ret;

	i = 0;
	ret = 0;
	while (wstring[i])
		i++;
	if ((ret = ft_strnew(((i * sizeof(wchar_t)) + 1))) == NULL)
		ft_failure(NULL, "Malloc failed");
	return (ret);
}

static char		*get_ws(t_env *e, t_arg *opt)
{
	wchar_t	*wstring;
	char	*ret;
	char	*temp;

	if ((wstring = va_arg(e->ap, wchar_t *)) == 0)
		return (0);
	ret = init_ret(wstring);
	while (*wstring)
	{
		temp = get_wc(*wstring, opt);
		if (opt->is_prec && ft_strlen(temp) + ft_strlen(ret)
			> (unsigned int)opt->prec)
		{
			ft_strdel(&temp);
			break ;
		}
		else
			ft_strcat(ret, temp);
		wstring++;
		ft_strdel(&temp);
	}
	opt->sizearg = ft_strlen(ret);
	return (ret);
}

void			ft_printwstr(t_env *e, t_arg *opt)
{
	char	*s;
	int		i;
	int		is_null;

	s = NULL;
	is_null = 0;
	i = 0;
	s = get_ws(e, opt);
	if (!s)
	{
		s = get_null_string(opt, e);
		is_null = 1;
	}
	i = opt->padding - opt->sizearg > 0 ? opt->padding - opt->sizearg + 1 : 1;
	put_padding_left(i, e, opt);
	ft_putstr(s);
	put_padding_right(i, e, opt);
	if (!ft_strequ(s, "(null)"))
		e->count += ft_strlen(s);
	else if (ft_strequ(s, "(null)") && !is_null)
		e->count += 6;
	ft_strdel(&s);
}
