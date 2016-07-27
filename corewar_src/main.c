/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:34:51 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/13 09:06:30 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include <stdlib.h>

static int			load_champions(t_core *c)
{
	size_t	i;
	int		ret;
	int		color;

	i = 0;
	color = 1;
	while (i < c->nb_warriors)
	{
		if ((ret = load_champion(c, c->warriors_path[i],
					c->warriors_numbers[i], color)) < 0)
			return (print_error(c->warriors_path[i], ret));
		free(c->warriors_path[i]);
		i++;
		color++;
	}
	ft_memdel((void **)&c->warriors_path);
	return (0);
}

int					main(int argc, char **argv)
{
	t_core		c;
	int			ret;

	if (argc == 1)
		usage();
	ft_bzero(&c, sizeof(c));
	parse_options(&c, argc, argv);
	if (load_champions(&c) < 0)
		return (1);
	if ((c.options & OPT_C) && (init_ncurses(&c) < 0))
	{
		ft_error("ncurse failed to initialize\n");
		return (3);
	}
	if ((ret = init_memory(&c)) < 0)
	{
		if (c.options & OPT_C)
			endwin();
		print_error("corewar: ", ret);
		return (1);
	}
	cycles_execution(&c);
	if (c.options & OPT_C)
		endwin();
	return (0);
}
