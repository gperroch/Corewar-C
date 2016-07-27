/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_mem_ncurses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:20:40 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/09 17:37:49 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		dump_mem_ncurses(t_core *c, WINDOW *win)
{
	int		i;
	int		x;
	int		y;
	char	*ptr;

	i = 0;
	x = 3;
	y = 2;
	ptr = c->mem;
	wattron(c->game, A_DIM);
	while (i < MEM_SIZE)
	{
		mvwprintw(win, y, x, "%02hhx", *ptr);
		ptr++;
		i++;
		x += 3;
		if (i % 64 == 0 || i == MEM_SIZE)
		{
			y++;
			x = 3;
		}
	}
	wattroff(c->game, A_DIM);
}
