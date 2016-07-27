/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:02:47 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/13 15:45:25 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		add_live(t_core *c, int nb)
{
	int			i;

	i = 0;
	while (c->warriors_numbers[i] != nb && i < MAX_PLAYERS)
		i++;
	(c->lives_tmp[i])++;
}

int				op_live(t_core *c, t_proc *process, int op_addr)
{
	int			nb_champ;
	t_warrior	*w;

	nb_champ = get_int(c, process);
	if ((w = get_champ_by_nb(c, nb_champ)) != NULL)
	{
		if (!(c->options & OPT_C)
		&& c->options & OPT_V && (c->verbose_level & 4))
			ft_printf("Un processus dit que le joueur %d(%s) est en vie\n",
				nb_champ, w->name);
		add_live(c, nb_champ);
	}
	process->live++;
	process->last_live = c->ncycles;
	if (c->options & OPT_V && (c->verbose_level & 4))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] --- "
		"champ[%d]\n",
		c->ncycles, "\033[32m", "OP_LIVE", "\033[0m", process->owner->number,
		op_addr, nb_champ);
	return (0);
}
