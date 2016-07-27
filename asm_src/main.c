/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:24:34 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/19 11:49:38 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

static void	ft_pusage(int big)
{
	if (!big)
	{
		ft_putendl_fd("Usage ./asm [-a] [-c] [-h] [-o newname filename.s] " \
			"<filename.s>", 2);
		exit(2);
	}
	else
	{
		ft_putendl_fd("Usage ./asm [-a] [-c] [-h] [-o newname filename.s] " \
			"<filename.s>", 2);
		ft_putendl_fd("	-a:	Instead of creating a .cor file," \
			"outputs a stripped\n		and annotated version of the code" \
			" to the standard output\n" \
			"	-o :	Specify output name of champion\n"
			"	-c :	Without color\n"
			"	-h :	Help", 2);
		exit(2);
	}
}

static void	ft_putheader(const char *filename)
{
	if (!(g_color & OPT_C))
		ft_putstr(BLUE_LIGHT);
	ft_putchar('[');
	ft_putstr(filename);
	ft_putchar(']');
	ft_putchar('\n');
	if (!(g_color & OPT_C))
		ft_putstr(DEFAULT);
}

static void	ft_reset_source(t_source *source)
{
	source->name = NULL;
	source->line = NULL;
	ft_bzero(&(source->header), sizeof(t_header));
}

static void	ft_parse_all(t_source *source, char *filename, char *newname)
{
	ft_reset_source(source);
	if (newname)
		source->name = ft_strdup(newname);
	ft_putheader(filename);
	if (ft_save_source(source, filename) < 0)
		return ;
	if (ft_lexical_analysis(source) < 0)
		return ;
	if (ft_create_bytecode(source) < 0)
		return ;
	if (source->options & OPT_A)
		ft_option_debug_champion(source);
	else
		ft_write_bytecode(source);
}

int			main(int ac, char **av)
{
	t_source	source;
	t_args		*arg;
	t_args		*tmp;

	if (ac == 1)
		ft_pusage(1);
	ft_bzero(&source, sizeof(t_source));
	arg = ft_parse_option(&source, av);
	if (source.options & OPT_H)
		ft_pusage(1);
	if (!arg)
		ft_pusage(1);
	if (source.options & OPT_BAD)
		ft_pusage(1);
	tmp = arg;
	while (tmp)
	{
		ft_parse_all(&source, tmp->filename, tmp->newname);
		tmp = tmp->next;
	}
	ft_free_list_args(&arg);
	return (0);
}
