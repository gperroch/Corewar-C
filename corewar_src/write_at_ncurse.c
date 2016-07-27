/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_at_ncurse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 16:25:37 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/12 10:59:45 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** function to write in ncurse mode a char at a given addres with the given
** color. Mainly used in write_int, used in st and sti operations
*/

void	write_at_ncurse(t_core *c, int addr, int color, char towrite)
{
	int		x;
	int		y;

	x = (addr % 64) + (addr % 64) * 2 + 3;
	y = (addr / 64) + 2;
	wattron(c->game, COLOR_PAIR(color));
	mvwprintw(c->game, y, x, "%02hhx", towrite);
	wattroff(c->game, COLOR_PAIR(color));
}
