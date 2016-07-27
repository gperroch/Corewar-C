/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 12:45:25 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 15:56:30 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		fail(t_proc *process, int op_addr)
{
	process->pc = (op_addr + 1) % MEM_SIZE;
	return (-1);
}

static int		fill_registers(t_core *c, t_proc *p, int reg[3])
{
	int		i;

	i = 0;
	while (i < 3)
	{
		reg[i] = c->mem[p->pc] - 1;
		if (reg[i] > 15 || reg[i] < 0)
			return (-1);
		inc_pc(p, 1);
		i++;
	}
	return (0);
}

int				op_add(t_core *c, t_proc *process, int op_addr)
{
	int		reg[3];

	if (c->mem[process->pc] != 84)
		return (fail(process, op_addr));
	inc_pc(process, 1);
	if (fill_registers(c, process, reg) < 0)
		return (fail(process, op_addr));
	if (c->options & OPT_V && (c->verbose_level & 8))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] --- r%d[%d]"
		" + r%d[%d]", c->ncycles, "\033[32m", "OP_ADD", "\033[0m",
		process->owner->number, op_addr, reg[0] + 1, process->regs[reg[0]],
		reg[1] + 1, process->regs[reg[1]]);
	process->regs[reg[2]] = process->regs[reg[0]] + process->regs[reg[1]];
	if (c->options & OPT_V && (c->verbose_level & 8))
		ft_printf(" => r%d[%d]\n", reg[2] + 1, process->regs[reg[2]]);
	process->carry = (process->regs[reg[2]] ? 0 : 1);
	return (0);
}
