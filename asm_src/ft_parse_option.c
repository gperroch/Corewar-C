/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:27:21 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/12 16:43:16 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

t_args		*ft_create_arg(char *filename, char *newname)
{
	t_args	*arg;

	arg = (t_args *)malloc(sizeof(t_args));
	arg->filename = filename;
	arg->newname = newname;
	arg->next = NULL;
	return (arg);
}

void		ft_add_to_arg(t_args **arg, t_args *new)
{
	t_args	*tmp_arg;

	if (!*arg)
		*arg = new;
	else
	{
		tmp_arg = *arg;
		while (tmp_arg->next)
			tmp_arg = tmp_arg->next;
		tmp_arg->next = new;
	}
}

static int	ft_get_filename(t_source *e, t_args **arg, char **av, int i)
{
	t_args	*new;

	if (av[i + 1] && av[i + 2])
	{
		new = ft_create_arg(ft_strdup(av[i + 2]), ft_strdup(av[i + 1]));
		ft_add_to_arg(arg, new);
		i += 2;
	}
	else
		e->options |= OPT_BAD;
	return (i);
}

int			ft_check_option(t_source **e, char **av, int i)
{
	if (!ft_strcmp(av[i], "-a"))
	{
		(*e)->options |= OPT_A;
		return (1);
	}
	else if (!ft_strcmp(av[i], "-c"))
	{
		(*e)->options |= OPT_C;
		return (1);
	}
	else if (!ft_strcmp(av[i], "-h"))
	{
		(*e)->options |= OPT_H;
		return (1);
	}
	return (0);
}

t_args		*ft_parse_option(t_source *e, char **av)
{
	t_args	*arg;
	t_args	*new;
	int		i;

	i = 0;
	arg = NULL;
	while (av[++i])
	{
		if (!ft_check_option(&e, av, i))
		{
			if (!ft_strcmp(av[i], "-o"))
				i = ft_get_filename(e, &arg, av, i);
			else if (av[i][0] && av[i][1] && av[i][0] == '-' &&
				av[i][1] != 'a' && av[i][1] != 'o' && av[i][1] != 'c')
				e->options |= OPT_BAD;
			else
			{
				new = ft_create_arg(ft_strdup(av[i]), NULL);
				ft_add_to_arg(&arg, new);
			}
		}
	}
	g_color = e->options;
	return (arg);
}
