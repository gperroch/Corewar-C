/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_champ_ncurse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:48:39 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 16:57:55 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_campeon(t_core *c, t_warrior *w, int from)
{
	if (!w)
		return ;
	wattron(c->log, COLOR_PAIR(w->color));
	mvwprintw(c->log, from, 2, "%s (%#x)", w->name, w->number);
	wattroff(c->log, COLOR_PAIR(w->color));
	mvwprintw(c->log, from + 1, 5, "procs:           %5d", w->nbprocs);
	mvwprintw(c->log, from + 2, 5, "lives in period: %5d",
				get_lives_by_champ(c, w->number));
}

void		display_champ_ncurse(t_core *c, int from)
{
	t_list	*wptr;

	if (!(wptr = c->warriors))
		return ;
	while (wptr)
	{
		print_campeon(c, wptr->content, from);
		from += 3;
		wptr = wptr->next;
	}
}
