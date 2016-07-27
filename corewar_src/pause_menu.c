/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:18:18 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/13 10:56:40 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		modif_ncurse_refresh(t_core *c, int less)
{
	if (less)
		c->ncurse_refresh--;
	else
		c->ncurse_refresh++;
}

static int		pause_loop(t_core *c, int ch)
{
	if (ch == 'q')
		get_out();
	else if (ch == 'p')
	{
		if (debug_process(c, DEBUG_OFFSET) == ' ')
			return (-1);
	}
	else if (ch == ' ')
	{
		c->debug_mode = 0;
		return (-1);
	}
	else if (ch == KEY_UP && (c->ncurse_refresh < 500))
		modif_ncurse_refresh(c, 0);
	else if (ch == KEY_DOWN && (c->ncurse_refresh > 1))
		modif_ncurse_refresh(c, 1);
	else if (ch == KEY_RIGHT)
	{
		c->debug_mode = 1;
		return (-1);
	}
	return (0);
}

static void		display_commands(t_core *c)
{
	wattron(c->log, A_BOLD);
	wattron(c->log, A_BLINK);
	mvwprintw(c->log, 49, 20, "*** GAME PAUSED ***");
	wattroff(c->log, A_BLINK);
	mvwprintw(c->log, 50, 2, "SPACEBAR : resume game");
	mvwprintw(c->log, 51, 2, "RIGHT    : increment cycle");
	mvwprintw(c->log, 52, 2, "UP/DOWN  : increment/decrement refresh rate");
	mvwprintw(c->log, 53, 2, "P        : dump processes");
	mvwprintw(c->log, 54, 2, "Q        : quit game");
	wattroff(c->log, A_BOLD);
}

static void		erase_commands(t_core *c)
{
	int	i;

	i = 49;
	while (i < 55)
	{
		mvwprintw(c->log, i, 2, "                                            ");
		i++;
	}
}

void			pause_menu(t_core *c)
{
	int		ch;

	nodelay(stdscr, FALSE);
	display_commands(c);
	while (42)
	{
		update_screen(c, 0);
		ch = getch();
		if (pause_loop(c, ch) < 0)
			break ;
	}
	if (c->debug_mode == 0)
		erase_commands(c);
	nodelay(stdscr, TRUE);
}
