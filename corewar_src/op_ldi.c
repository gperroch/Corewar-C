/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:40:28 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 15:43:13 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** ldi r1, r2, r3		 	==	0a54 0102 03		REG 1o,	REG 1o, REG 1o + ocp
** ldi %2864434397, r2, r3 	==	0a94 ccdd 0203 		DIR 2o, REG 1o, REG 1o + ocp
** ldi 2864434397, r2, r3 	==	0ad4 ccdd 0203 		IND 2o, REG 1o, REG 1o + ocp
*/

static int		fail(t_proc *process, int op_addr)
{
	process->pc = (op_addr + 1) % MEM_SIZE;
	return (-1);
}

static int		get_param1(t_core *c, t_proc *p, int *param, int op_addr)
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
		*param = get_short(c, p);
	else if (ocp >> 6 == IND_CODE)
		*param = get_int_from(c,
			modulo(op_addr + (get_short(c, p) % IDX_MOD), MEM_SIZE));
	else
		return (-1);
	return (0);
}

static int		get_param2(t_core *c, t_proc *p, int *param, int op_addr)
{
	unsigned char	ocp;

	ocp = c->mem[(op_addr + 1) % MEM_SIZE];
	ocp = ((ocp << 2) >> 6) & 3;
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
	else
		return (-1);
	return (0);
}

int				op_ldi(t_core *c, t_proc *process, int op_addr)
{
	int				param[3];
	unsigned char	ocp;

	ocp = c->mem[process->pc % MEM_SIZE];
	inc_pc(process, 1);
	if (get_param1(c, process, &param[0], op_addr) < 0)
		return (fail(process, op_addr));
	if (get_param2(c, process, &param[1], op_addr) < 0)
		return (fail(process, op_addr));
	param[2] = c->mem[process->pc % MEM_SIZE];
	if ((((ocp >> 2) & 3) != REG_CODE) || (param[2] < 1 || param[2] > 16))
		return (fail(process, op_addr));
	inc_pc(process, 1);
	process->regs[param[2] - 1] = get_int_from(c,
		modulo(op_addr + ((param[0] + param[1]) % IDX_MOD), MEM_SIZE));
	if (c->options & OPT_V && (c->verbose_level & 32))
		ft_printf("(cycle: %6d) %s%-8s%s (owner: %3d) : op_addr[%d] ---"
		" *(%d) = [%d] => r%d\n", c->ncycles, "\033[32m", "OP_LDI", "\033[0m",
		process->owner->number, op_addr,
		modulo(op_addr + ((param[0] + param[1]) % IDX_MOD), MEM_SIZE),
		process->regs[param[2] - 1], param[2]);
	return (0);
}
