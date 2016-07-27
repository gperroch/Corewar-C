/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 10:55:30 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 15:42:23 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		fail(t_proc *process, int op_addr)
{
	process->pc = (op_addr + 1) % MEM_SIZE;
	return (-1);
}

static int		get_param2(t_core *c, t_proc *p, int *param, int op_addr)
{
	unsigned char	ocp;

	ocp = c->mem[(op_addr + 1) % MEM_SIZE];
	ocp = (ocp >> 4) & 3;
	if (ocp == REG_CODE)
	{
		*param = c->mem[p->pc];
		inc_pc(p, 1);
		if (*param <= 0 || *param > 16)
			return (-1);
		*param = p->regs[(*param) - 1];
	}
	else if (ocp == DIR_CODE)
		*param = get_short(c, p);
	else if (ocp == IND_CODE)
		*param = get_int_from(c,
			modulo(op_addr + (get_short(c, p) % IDX_MOD), MEM_SIZE));
	else
		return (-1);
	return (0);
}

static int		get_param3(t_core *c, t_proc *p, int *param, int op_addr)
{
	unsigned char	ocp;

	ocp = c->mem[(op_addr + 1) % MEM_SIZE];
	ocp = (ocp >> 2) & 3;
	if (ocp == REG_CODE)
	{
		*param = c->mem[p->pc];
		if (*param < 1 || *param > 16)
			return (-1);
		*param = p->regs[*param - 1];
		inc_pc(p, 1);
	}
	else if (ocp == DIR_CODE)
		*param = get_short(c, p);
	else
		return (-1);
	return (0);
}

int				op_sti(t_core *c, t_proc *process, int op_addr)
{
	int		params[3];
	int		reg;
	char	opc;

	opc = c->mem[process->pc % MEM_SIZE];
	inc_pc(process, 1);
	params[0] = c->mem[process->pc];
	reg = params[0];
	if (((opc >> 6) & 3) != REG_CODE || params[0] < 1 || params[0] > 16)
		return (fail(process, op_addr));
	params[0] = process->regs[params[0] - 1];
	inc_pc(process, 1);
	if ((get_param2(c, process, &params[1], op_addr) < 0)
	|| (get_param3(c, process, &params[2], op_addr) < 0))
		return (fail(process, op_addr));
	write_int(c, process->color, params[0],
		modulo(op_addr + ((params[1] + params[2]) % IDX_MOD), MEM_SIZE));
	if (c->options & OPT_V && (c->verbose_level & 64))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] ---"
		" r%d[%d] => mod(%d + (([%d]+[%d]) %% 512), 4096)=[%d]\n",
		c->ncycles, "\033[32m", "OP_STI", "\033[0m", process->owner->number,
		op_addr, reg, params[0], op_addr, params[1], params[2],
		modulo(op_addr + ((params[1] + params[2]) % IDX_MOD), MEM_SIZE));
	return (0);
}
