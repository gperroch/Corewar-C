/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:43:34 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 15:58:46 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			fail(t_proc *process, int op_addr)
{
	process->pc = (op_addr + 1) % MEM_SIZE;
	return (-1);
}

static int			get_param1(t_core *c, t_proc *p, int *param, int op_addr)
{
	unsigned char	ocp;

	ocp = c->mem[(op_addr + 1) % MEM_SIZE];
	if (ocp >> 6 == REG_CODE)
	{
		*param = c->mem[p->pc];
		inc_pc(p, 1);
		if (*param <= 0 || *param > 16)
			return (-1);
		*param = p->regs[(*param) - 1];
	}
	else if (ocp >> 6 == DIR_CODE)
		*param = get_int(c, p);
	else if (ocp >> 6 == IND_CODE)
		*param = get_int_from(c,
			modulo(op_addr + (get_short(c, p) % IDX_MOD), MEM_SIZE));
	else
		return (-1);
	return (0);
}

static int			get_param2(t_core *c, t_proc *p, int *param, int op_addr)
{
	unsigned char	ocp;

	ocp = c->mem[(op_addr + 1) % MEM_SIZE];
	if (((ocp >> 4) & 3) == REG_CODE)
	{
		*param = c->mem[p->pc];
		inc_pc(p, 1);
		if (*param <= 0 || *param > 16)
			return (-1);
		*param = p->regs[(*param) - 1];
	}
	else if (((ocp >> 4) & 3) == DIR_CODE)
		*param = get_int(c, p);
	else if (((ocp >> 4) & 3) == IND_CODE)
		*param = get_int_from(c,
			modulo(op_addr + (get_short(c, p) % IDX_MOD), MEM_SIZE));
	else
		return (-1);
	return (0);
}

int					op_xor(t_core *c, t_proc *process, int op_addr)
{
	unsigned char	ocp;
	int				params[3];

	ocp = c->mem[process->pc % MEM_SIZE];
	inc_pc(process, 1);
	if ((get_param1(c, process, &params[0], op_addr) < 0)
	|| (get_param2(c, process, &params[1], op_addr) < 0))
		return (fail(process, op_addr));
	if (((ocp >> 2) & 3) == REG_CODE)
	{
		params[2] = c->mem[process->pc];
		inc_pc(process, 1);
		if (params[2] <= 0 || params[2] > 16)
			return (fail(process, op_addr));
	}
	else
		return (fail(process, op_addr));
	process->regs[params[2] - 1] = params[0] ^ params[1];
	process->carry = process->regs[params[2] - 1] ? 0 : 1;
	if (c->options & OPT_V && (c->verbose_level & 16))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] --- "
		"param1[%d] & param2[%d] -> r%d\n",
		c->ncycles, "\033[32m", "OP_XOR", "\033[0m", process->owner->number,
		op_addr, params[0], params[1], params[2]);
	return (0);
}
