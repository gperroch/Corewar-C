/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:44:34 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/10 11:47:57 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		fail(t_proc *process, int op_addr)
{
	process->pc = (op_addr + 1) % MEM_SIZE;
	return (-1);
}

int				op_aff(t_core *c, t_proc *process, int op_addr)
{
	int		to_aff;
	int		reg;

	inc_pc(process, 1);
	reg = c->mem[process->pc];
	if (reg <= 0 || reg > 16)
		return (fail(process, op_addr));
	to_aff = (unsigned char)(process->regs[reg - 1]) % 256;
	if (!(c->options & OPT_C))
		ft_putchar(to_aff);
	inc_pc(process, 1);
	(void)op_addr;
	if (c->options & OPT_V && (c->verbose_level & 256))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %d) : op_addr[%d] --- [%d]\n",
		c->ncycles, "\033[32m", "OP_AFF", "\033[0m", process->owner->number,
		op_addr, to_aff);
	return (0);
}
