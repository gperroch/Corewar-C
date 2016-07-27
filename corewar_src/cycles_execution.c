/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:27:17 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/19 09:58:20 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

static void		handle_options(t_core *c)
{
	if (c->options & OPT_C)
		update_ncurses(c);
	if ((c->options & OPT_DUMP) && c->ncycles == c->dumps)
	{
		if (c->options & OPT_C)
			endwin();
		dump_mem(c);
		exit(0);
	}
	if ((c->options & OPT_S) && !(c->options & OPT_C) && (c->sdumps > 0)
	&& !(c->ncycles % c->sdumps))
	{
		dump_mem(c);
		while (!getchar())
			;
	}
}

static void		check_ctl(t_core *c)
{
	if (c->cycle_to_die <= 0)
		end_game(c);
}

static void		warrior_loop(t_core *c)
{
	t_list		*ptr_w;
	t_list		*ptr_p;
	t_warrior	*warrior;
	t_proc		*process;

	ptr_w = c->warriors;
	while (ptr_w)
	{
		warrior = (t_warrior *)ptr_w->content;
		if (!warrior || !warrior->procs)
		{
			ptr_w = ptr_w->next;
			continue;
		}
		ptr_p = warrior->procs;
		while (ptr_p)
		{
			process = (t_proc *)ptr_p->content;
			ptr_p = ptr_p->next;
			check_ctl(c);
			if (process)
				process_execution(c, process);
		}
		ptr_w = ptr_w->next;
	}
}

void			cycles_execution(t_core *c)
{
	int			nbr_checks;

	nbr_checks = 0;
	c->cycle_to_die = CYCLE_TO_DIE;
	if (c->options & OPT_C)
	{
		update_screen(c, 0);
		pause_menu(c);
	}
	while (c->cycle_to_die > 0 && still_alive(c))
	{
		c->ncycles_tmp++;
		c->ncycles++;
		if (c->ncycles > 0 && c->ncycles_tmp == c->cycle_to_die)
			verification_cycle(c, &nbr_checks);
		warrior_loop(c);
		handle_options(c);
	}
}
