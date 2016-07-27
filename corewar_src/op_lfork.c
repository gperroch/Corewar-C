/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:23:35 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 16:19:49 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Pareil qu'un fork, mais sans modulo a l'adresse
*/

int				op_lfork(t_core *c, t_proc *process, int op_addr)
{
	t_proc	new;
	short	index;

	ft_memcpy(&new, process, sizeof(new));
	index = get_short(c, process);
	new.pc = modulo(op_addr + index, MEM_SIZE);
	new.current_op = -1;
	new.cycles = 1;
	new.cyclelimit = 0;
	ft_lstadd(&new.owner->procs, ft_lstnew(&new, sizeof(new)));
	process->carry = 1;
	c->totalprocs++;
	process->owner->nbprocs++;
	if (c->options & OPT_V && (c->verbose_level & 128))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] ---"
		" new_process.pc[%d]\n",
		c->ncycles, "\033[32m", "OP_LFORK", "\033[0m", process->owner->number,
		op_addr, modulo(op_addr + index, MEM_SIZE));
	return (0);
}
