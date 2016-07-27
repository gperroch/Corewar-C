/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:23:35 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 16:20:05 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				op_fork(t_core *c, t_proc *process, int op_addr)
{
	t_proc	new;
	short	index;

	(void)op_addr;
	ft_memcpy(&new, process, sizeof(new));
	index = get_short(c, process);
	new.pc = modulo((op_addr + (index % IDX_MOD)), MEM_SIZE);
	new.current_op = -1;
	new.cycles = 1;
	new.cyclelimit = 0;
	ft_lstadd(&new.owner->procs, ft_lstnew(&new, sizeof(new)));
	process->carry = 1;
	c->totalprocs++;
	process->owner->nbprocs++;
	if (c->options & OPT_V && (c->verbose_level & 128))
		ft_printf("(cycle: %6d) %s%-5s%s (owner: %d) : op_addr[%d] ---"
		" new_process.pc[%d]\n",
		c->ncycles, "\033[32m", "OP_FORK", "\033[0m", process->owner->number,
		op_addr, modulo((op_addr + (index % IDX_MOD)), MEM_SIZE));
	return (0);
}
