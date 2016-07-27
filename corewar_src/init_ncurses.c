/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 11:48:54 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/12 10:57:41 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_color_game(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
}

static WINDOW	*create_newwin(int height, int width, int starty, int startx)
{
	return (newwin(height, width, starty, startx));
}

static void		draw_boxes(t_core *c)
{
	wattron(c->game, A_REVERSE);
	wattron(c->log, A_REVERSE);
	box(c->game, '#', '#');
	box(c->log, '#', '#');
	wattroff(c->game, A_REVERSE);
	wattroff(c->log, A_REVERSE);
	dump_mem_ncurses(c, c->game);
}

int				init_ncurses(t_core *c)
{
	initscr();
	if (LINES < 61 || COLS < 221)
	{
		ft_printf("%d et %d, need 70 et 273\n", LINES, COLS);
		endwin();
		ft_error("Window is too small for ncurse mode, exiting...\n");
		return (-1);
	}
	clear();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	init_color_game();
	curs_set(0);
	if (!(c->game = create_newwin(68, 197, 1, 1))
	|| !(c->log = create_newwin(68, 75, 1, 198)))
	{
		endwin();
		return (-1);
	}
	c->ncurse_refresh = NCURSE_REFRESH;
	draw_boxes(c);
	return (0);
}
