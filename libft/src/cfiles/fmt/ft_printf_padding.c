/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 11:25:10 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:35:12 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "io.h"
#include "ft_ctypes.h"
#include "strconv.h"
#include "str.h"

/*
** get_padding starts at the first digit encountered after a % (except 0)
*/

int		get_padding(char *format, t_arg *opt, t_env *e)
{
	int			size;
	char		*padding;
	int			i;
	char		*ptr;

	i = -1;
	size = 0;
	padding = NULL;
	e->ipadding = e->iparse;
	ptr = &format[e->ipadding];
	while (format[e->ipadding] && ft_isdigit(format[e->ipadding]))
	{
		size++;
		e->ipadding++;
	}
	if ((padding = ft_strnew((size + 1) * sizeof(char))) == NULL)
		ft_failure(NULL, "Malloc failed");
	while (ptr[++i] && ft_isdigit(ptr[i]))
		padding[i] = ptr[i];
	opt->padding = ft_atoi(padding);
	ft_strdel(&padding);
	e->iparse += size;
	return (0);
}

void	put_padding_left(int i, t_env *e, t_arg *opt)
{
	if (opt->padding && opt->justif == 'r')
	{
		while (--i > 0)
		{
			ft_putchar(opt->typepad);
			e->count++;
		}
	}
}

void	put_padding_right(int i, t_env *e, t_arg *opt)
{
	if (opt->padding && opt->justif == 'l')
	{
		while (--i > 0)
		{
			ft_putchar(' ');
			e->count++;
		}
	}
}

void	put_padding_nb_left(t_env *e, t_arg *opt)
{
	int	i;

	if ((!opt->is_prec && opt->typepad == '0' && opt->padding > opt->sizearg
		&& opt->justif == 'r')
		|| (opt->is_prec && opt->typepad == '0' && ft_strchr("cC", opt->type)))
		return ;
	if (opt->padding > opt->sizearg && opt->justif == 'r')
	{
		i = opt->padding - opt->sizearg + 1;
		while (--i > 0)
		{
			ft_putchar(' ');
			e->count++;
		}
	}
}

void	put_padding_nb_right(t_env *e, t_arg *opt)
{
	int	i;

	if (opt->padding > opt->sizearg && opt->justif == 'l')
	{
		i = opt->padding - opt->sizearg + 1;
		while (--i > 0)
		{
			ft_putchar(' ');
			e->count++;
		}
	}
}
