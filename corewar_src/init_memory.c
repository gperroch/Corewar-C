/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:58:20 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/14 15:21:01 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** func to load champ code in the machine memory
*/

static void		init_champ_in_mem(t_core *c, t_warrior *w, size_t offset)
{
	ft_memcpy(c->mem + offset, w->code, w->size);
	ft_memset(c->memcolor + offset, w->color, w->size);
	if (c->options & OPT_C)
		init_memory_ncurses(c, w, offset);
	init_proc(w, offset);
	c->totalprocs++;
}

int				init_memory(t_core *c)
{
	int			i;
	t_warrior	*w;
	t_list		*ptr;
	size_t		offset;

	ptr = c->warriors;
	if (!ptr || c->nb_warriors == 0)
		return (NO_CHAMPS);
	if (c->nb_warriors > MAX_PLAYERS)
		return (TOO_MANY_CHAMPS);
	i = 0;
	while (ptr)
	{
		if (!(w = (t_warrior *)ptr->content))
			return (-1);
		offset = i * (MEM_SIZE / c->nb_warriors);
		if (offset + w->size < MEM_SIZE)
			init_champ_in_mem(c, w, offset);
		ptr = ptr->next;
		i++;
	}
	return (0);
}
