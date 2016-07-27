/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_cycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 09:39:39 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/13 15:25:23 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		synchro_lives(t_core *c)
{
	int			i;

	i = c->nb_warriors;
	while (--i >= 0)
	{
		c->lives_total[i] += c->lives_tmp[i];
		if (c->lives_tmp[i] && c->last_warrior)
			c->last_warrior = 0;
		if (c->lives_tmp[i] && !c->last_warrior)
			c->last_warrior = c->warriors_numbers[i];
	}
}

static void		check_lives_process(t_core *c)
{
	t_list		*ptr_w;
	t_list		*ptr_p;
	t_warrior	*warrior;
	t_proc		*process;

	ptr_w = c->warriors;
	while (ptr_w)
	{
		warrior = (t_warrior *)ptr_w->content;
		ptr_p = warrior->procs;
		while (ptr_p)
		{
			process = (t_proc *)ptr_p->content;
			ptr_p = ptr_p->next;
			if ((c->ncycles - process->last_live) > c->cycle_to_die
			|| !process->live)
				kill_process(c, warrior, process);
			else
				process->live = 0;
		}
		ptr_w = ptr_w->next;
	}
}

static int		no_live(int *lives_tmp, int nb_warriors)
{
	while (--nb_warriors >= 0)
	{
		if (lives_tmp[nb_warriors])
			return (1);
	}
	return (0);
}

static int		cumul_lives(int *lives, int nb)
{
	int			total;

	total = 0;
	while (--nb >= 0)
	{
		total += lives[nb];
		lives[nb] = 0;
	}
	return (total);
}

void			verification_cycle(t_core *c, int *nbr_checks)
{
	int			cumul;

	if (!no_live(c->lives_tmp, c->nb_warriors))
		end_game(c);
	synchro_lives(c);
	check_lives_process(c);
	cumul = cumul_lives(c->lives_tmp, c->nb_warriors);
	if (c->options & OPT_V && (c->verbose_level & 2))
		ft_printf("(cycle: %6d) %sVERIFICATION%s nbr_checks = %d, cumul = %d\n",
		c->ncycles, "\033[31m", "\033[0m", *nbr_checks, cumul);
	if (cumul >= NBR_LIVE || *nbr_checks == MAX_CHECKS - 1)
	{
		c->cycle_to_die -= CYCLE_DELTA;
		if (c->options & OPT_V && c->verbose_level & 2)
			ft_printf("At cycle %d : cycles to die is now %d\n", c->ncycles,
			c->cycle_to_die);
		*nbr_checks = 0;
	}
	else
		(*nbr_checks)++;
	c->ncycles_tmp = 0;
}
