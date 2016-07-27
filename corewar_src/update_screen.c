/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:21:34 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 13:11:35 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

void		update_screen(t_core *c, int wait)
{
	wattron(c->log, A_BOLD);
	mvwprintw(c->log, 2, 2, "Cycles:        %10d", c->ncycles);
	mvwprintw(c->log, 3, 2, "Cycles to die: %10d", c->cycle_to_die);
	mvwprintw(c->log, 4, 2, "Refresh every  %10d", c->ncurse_refresh);
	mvwprintw(c->log, 5, 2, "Total procs:   %10zd", c->totalprocs);
	display_champ_ncurse(c, 7);
	wattroff(c->log, A_BOLD);
	refresh_screen(c);
	if (wait)
		usleep(NCURSE_SLEEP);
}
