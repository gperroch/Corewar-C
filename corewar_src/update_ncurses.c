/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ncurses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:12:32 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/09 17:29:58 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			update_ncurses(t_core *c)
{
	unsigned int		ch;

	if ((c->ncycles % c->ncurse_refresh) == 0 || c->debug_mode == 1)
		update_screen(c, 1);
	if (c->debug_mode)
	{
		pause_menu(c);
		return ;
	}
	ch = getch();
	if (ch == 'q')
		get_out();
	else if (ch == KEY_UP && (c->ncurse_refresh < 500))
		c->ncurse_refresh++;
	else if (ch == KEY_DOWN && (c->ncurse_refresh > 1))
		c->ncurse_refresh--;
	else if (ch == ' ')
		pause_menu(c);
}
