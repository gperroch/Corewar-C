/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 10:55:30 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 09:32:14 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		fail(t_core *c, t_proc *process, int op_addr)
{
	if (c->options & OPT_V && (c->verbose_level == 2 || c->verbose_level == 3))
		ft_printf("ST FAILURE (owner : %d)\n", process->owner->number);
	process->pc = (op_addr + 1) % MEM_SIZE;
	return (-1);
}

static int		do_param2(t_core *c, t_proc *p, int params[2], int op_addr)
{
	unsigned char	code;

	code = c->mem[(op_addr + 1) % MEM_SIZE];
	code = (code >> 4) & 3;
	if (code == REG_CODE)
	{
		params[1] = c->mem[p->pc];
		if (params[1] < 1 || params[1] > 16)
			return (-1);
		p->regs[params[1] - 1] = params[0];
		inc_pc(p, 1);
	}
	else if (code == IND_CODE)
	{
		params[1] = get_short(c, p);
		write_int(c, p->color, params[0],
				modulo(op_addr + (params[1] % IDX_MOD), MEM_SIZE));
	}
	else
		return (-1);
	return (0);
}

int				op_st(t_core *c, t_proc *process, int op_addr)
{
	int				params[2];
	int				reg;
	unsigned char	opc;

	opc = c->mem[process->pc % MEM_SIZE];
	inc_pc(process, 1);
	params[0] = c->mem[process->pc];
	reg = params[0];
	if (((opc >> 6) & 3) != REG_CODE || params[0] < 1 || params[0] > 16)
		return (fail(c, process, op_addr));
	params[0] = process->regs[params[0] - 1];
	inc_pc(process, 1);
	if (do_param2(c, process, params, op_addr) < 0)
		return (fail(c, process, op_addr));
	if (c->options & OPT_V && (c->verbose_level & 64))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] --- "
		"r%d[%d] => [%d]\n", c->ncycles, "\033[32m", "OP_ST", "\033[0m",
		process->owner->number, op_addr, reg, params[0],
		modulo(op_addr + (params[1] % IDX_MOD), MEM_SIZE));
	return (0);
}
