/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory_ncurses.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 14:03:19 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/09 17:25:14 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** in ncurse mode, function to display the right color of champions when they
** are loaded at the beginning of the game.
*/

int			init_memory_ncurses(t_core *c, t_warrior *w, size_t offset)
{
	size_t	i;
	int		x;
	int		y;

	if (!w || !c->game)
		return (-1);
	i = 0;
	x = (offset % 64) + ((offset % 64) * 2) + 3;
	y = (offset / 64) + 2;
	wattron(c->game, COLOR_PAIR(w->color));
	while (i < w->size)
	{
		mvwprintw(c->game, y, x, "%02hhx", w->code[i]);
		i++;
		offset++;
		x += 3;
		if (x >= 194)
		{
			y++;
			x = 3;
		}
	}
	wattroff(c->game, COLOR_PAIR(w->color));
	update_screen(c, 0);
	return (0);
}
