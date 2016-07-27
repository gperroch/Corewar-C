/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 09:33:44 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 15:42:45 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** zum beispiel :
** ld 	%2864434397, r1 == 0290 aabb ccdd 01	DIR 4o, REG 1o
** ld 	2864434397,	 r1 == 02d0 ccdd 01			IND 2o, REG 1o
*/

static int		fail(t_proc *process, int op_addr)
{
	process->pc = (op_addr + 1) % MEM_SIZE;
	return (-1);
}

int				op_ld(t_core *c, t_proc *process, int op_addr)
{
	char	ocp;
	int		param;
	int		reg;

	ocp = c->mem[process->pc % MEM_SIZE];
	inc_pc(process, 1);
	if (((ocp >> 6) & 3) == IND_CODE)
		param = get_int_from(c,
			modulo(op_addr + (get_short(c, process) % IDX_MOD), MEM_SIZE));
	else if (((ocp >> 6) & 3) == DIR_CODE)
		param = get_int(c, process);
	else
		return (fail(process, op_addr));
	reg = c->mem[process->pc % MEM_SIZE];
	if (reg <= 0 || reg > 16)
		return (fail(process, op_addr));
	process->regs[reg - 1] = param;
	process->carry = process->regs[reg - 1] ? 0 : 1;
	inc_pc(process, 1);
	if (c->options & OPT_V && (c->verbose_level & 32))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] --- "
					"param[%d] => r%d\n",
		c->ncycles, "\033[32m", "OP_LD", "\033[0m", process->owner->number,
		op_addr, param, reg);
	return (0);
}
