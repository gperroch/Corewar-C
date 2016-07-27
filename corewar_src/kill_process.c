/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 17:23:09 by gperroch          #+#    #+#             */
/*   Updated: 2016/05/12 14:57:04 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	kill_in_ncurse(t_core *c, t_proc *p)
{
	int	x;
	int	y;

	if (!p)
		return ;
	x = (p->pc % 64) + (p->pc % 64) * 2 + 3;
	y = (p->pc / 64) + 2;
	wattron(c->game, COLOR_PAIR(c->memcolor[p->pc]));
	mvwprintw(c->game, y, x, "%02hhx", c->mem[p->pc]);
	wattroff(c->game, COLOR_PAIR(c->memcolor[p->pc]));
	beep();
}

static void	update_nbprocs(t_core *c, t_warrior *w)
{
	c->totalprocs = c->totalprocs > 0 ? c->totalprocs - 1 : 0;
	w->nbprocs = w->nbprocs > 0 ? w->nbprocs - 1 : 0;
}

void		kill_process(t_core *c, t_warrior *w, t_proc *p)
{
	t_list	*ptr_p;
	t_list	**pp;

	if (!w || !w->procs)
		return ;
	ptr_p = w->procs;
	pp = &w->procs;
	while (ptr_p)
	{
		if (ptr_p->content == p)
		{
			*pp = ptr_p->next;
			if (c->options & OPT_C)
				kill_in_ncurse(c, ptr_p->content);
			free(ptr_p->content);
			free(ptr_p);
			update_nbprocs(c, w);
			if (c->options & OPT_V && (c->verbose_level & 2))
				ft_printf("(cycle: %6d) %sKill process%s (owner: %3d)\n",
				c->ncycles, "\033[31m", "\033[0m", w->number);
			return ;
		}
		pp = &ptr_p->next;
		ptr_p = ptr_p->next;
	}
}
