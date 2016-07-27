/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:35:10 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:55:25 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "io.h"
#include "ft_ctypes.h"
#include "strconv.h"
#include "str.h"

/*
** get_precision starts at the point. If there is no digit behind, it advances
** and set the precision to 0. If there is precision, it advances e->iparse to
** go to the character after the last digit.
*/

static void	get_prec_init(t_arg *opt, t_env *e, int *size, int *i)
{
	*size = 0;
	*i = -1;
	opt->is_prec = 1;
	opt->prec = 0;
	e->iprec = e->iparse + 1;
}

void		get_precision(char *format, t_arg *opt, t_env *e)
{
	int			size;
	char		*prec;
	int			i;
	char		*ptr;

	get_prec_init(opt, e, &size, &i);
	if (ft_isdigit(format[e->iprec]) == 0)
	{
		e->iparse++;
		return ;
	}
	ptr = &format[e->iprec];
	while (format[e->iprec] && ft_isdigit(format[e->iprec]))
	{
		size++;
		e->iprec++;
	}
	if ((prec = ft_strnew((size + 1) * sizeof(char))) == NULL)
		ft_failure(NULL, "Malloc failed");
	while (ptr[++i] && ft_isdigit(ptr[i]))
		prec[i] = ptr[i];
	opt->prec = ft_atoi(prec);
	ft_strdel(&prec);
	e->iparse += size + 1;
}
