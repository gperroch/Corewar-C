/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 10:52:26 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/10 13:48:00 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				op_zjmp(t_core *c, t_proc *process, int op_addr)
{
	short	index;

	if (process->carry == 0)
		return (-1);
	index = get_short(c, process);
	process->pc = modulo(op_addr + (index % IDX_MOD), MEM_SIZE);
	if (c->options & OPT_V && (c->verbose_level & 128))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] ---"
		" jump to [%d]\n",
		c->ncycles, "\033[32m", "OP_ZJMP", "\033[0m", process->owner->number,
		op_addr, modulo(op_addr + (index % IDX_MOD), MEM_SIZE));
	return (0);
}
