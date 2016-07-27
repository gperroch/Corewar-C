/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 09:39:01 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/19 14:03:27 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		end_game(t_core *c)
{
	t_list		*ptr_w;
	t_warrior	*warrior;

	ptr_w = c->warriors;
	warrior = NULL;
	while (!warrior && ptr_w)
	{
		warrior = (t_warrior *)ptr_w->content;
		if (warrior->number != c->last_warrior)
			warrior = NULL;
		ptr_w = ptr_w->next;
	}
	if (c->options & OPT_C)
		endwin();
	if (warrior)
		ft_printf("Le joueur %d(%s) a gagne\n", c->last_warrior, warrior->name);
	ft_printf("Game lasted %d cycles\n", c->ncycles);
	exit(0);
}
