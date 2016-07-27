/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pc_ncurses.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:29:12 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/09 13:40:20 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		update_pc_ncurses(t_core *c, int old, int pc)
{
	int		x;
	int		y;

	old = modulo(old, MEM_SIZE);
	pc = modulo(pc, MEM_SIZE);
	x = (old % 64) + (old % 64) * 2 + 3;
	y = (old / 64) + 2;
	wattron(c->game, COLOR_PAIR(c->memcolor[old]));
	mvwprintw(c->game, y, x, "%02hhx", c->mem[old]);
	wattroff(c->game, COLOR_PAIR(c->memcolor[old]));
	x = (pc % 64) + (pc % 64) * 2 + 3;
	y = (pc / 64) + 2;
	wattron(c->game, COLOR_PAIR(c->memcolor[pc]) | A_REVERSE);
	mvwprintw(c->game, y, x, "%02hhx", c->mem[pc]);
	wattroff(c->game, COLOR_PAIR(c->memcolor[pc]) | A_REVERSE);
}
