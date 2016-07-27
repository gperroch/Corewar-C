/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:27:55 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/13 11:49:14 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Function to dump process in ncurse
*/

static void			dump_registers(t_core *c, t_proc *p, int from)
{
	int		lol;

	if (!(c->options & OPT_C))
		return ;
	lol = 0;
	mvwprintw(c->log, from, 2, "REGISTERS");
	while (lol < 16)
	{
		mvwprintw(c->log, from + lol + 1, 2, "r%-2d: %10d", lol + 1,
		p->regs[lol]);
		lol++;
	}
}

static void			hightlight_proc(t_core *c, int pc, int normal)
{
	int		x;
	int		y;

	x = (pc % 64) + (pc % 64) * 2 + 3;
	y = (pc / 64) + 2;
	if (normal)
	{
		wattron(c->game, COLOR_PAIR(c->memcolor[pc]) | A_REVERSE);
		mvwprintw(c->game, y, x, "%02hhx", c->mem[pc]);
		wattroff(c->game, COLOR_PAIR(c->memcolor[pc]) | A_REVERSE);
	}
	else
	{
		wattron(c->game, COLOR_PAIR(c->memcolor[pc]) | A_STANDOUT | A_BLINK);
		mvwprintw(c->game, y, x, "%02hhx", c->mem[pc]);
		wattroff(c->game, COLOR_PAIR(c->memcolor[pc]) | A_STANDOUT | A_BLINK);
	}
}

static int			end_debug(t_core *c, int ch, int from)
{
	while (from < 49)
	{
		mvwprintw(c->log, from, 2, "                                         "
			"                             ");
		from++;
	}
	return (ch);
}

static int			dump_process(t_core *c, t_proc *p, int from)
{
	int		ch;

	wattron(c->log, A_BOLD);
	mvwprintw(c->log, from + 1, 2, "PROCESS %p", p);
	mvwprintw(c->log, from + 2, 2, "pc    : %4d", p->pc);
	mvwprintw(c->log, from + 3, 2, "carry : %4d", p->carry);
	mvwprintw(c->log, from + 4, 2, "op    : %4d             ", p->current_op);
	if (p->current_op > 0 && p->current_op < 17)
		mvwprintw(c->log, from + 4, 15, "(%s)",
			g_op_tab[p->current_op - 1].name);
	mvwprintw(c->log, from + 5, 2, "cycles: %4zd", p->cycles);
	mvwprintw(c->log, from + 6, 2, "limit : %4zd", p->cyclelimit);
	mvwprintw(c->log, from + 7, 2, "lives : %4d", p->live);
	mvwprintw(c->log, from + 8, 2, "last  : %4d", p->last_live);
	mvwprintw(c->log, from + 9, 2, "owner : %-30s", p->owner->name);
	dump_registers(c, p, from + 10);
	hightlight_proc(c, p->pc, 0);
	update_screen(c, 0);
	ch = getch();
	hightlight_proc(c, p->pc, 1);
	update_screen(c, 0);
	return (ch);
}

int					debug_process(t_core *c, int from)
{
	t_list	*wptr;
	t_list	*pptr;
	int		ch;

	if (!(wptr = c->warriors))
		return (8);
	while (wptr)
	{
		if (!(pptr = ((t_warrior *)wptr->content)->procs))
		{
			wptr = wptr->next;
			continue;
		}
		while (pptr)
		{
			if ((ch = dump_process(c, pptr->content, from)) == 'p')
				pptr = pptr->next;
			else
				return (end_debug(c, ch, from));
		}
		wptr = wptr->next;
		if (ch == 'p' && !wptr)
			wptr = c->warriors;
	}
	return (0);
}
