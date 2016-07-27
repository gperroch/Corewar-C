/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:21:09 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/13 14:17:02 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Analyse de la mémoire pointée par le PC, determine si il s'agit
**  d'une instruction;
**	Decrémente process->cycles;
**	Exécute l'instrution pointee si process->cycles == 0
**  et que process->cyclelimit != 0 (instruction requise);
**	Incremente le pc si il n'y a pas d'instruction a executer;
*/

static int		process_is_waiting(t_proc *p)
{
	return (p && (p->current_op != -1) && (p->cycles < p->cyclelimit));
}

static void		reinit_cycles(t_proc *p)
{
	p->current_op = -1;
	p->cycles = 1;
	p->cyclelimit = 0;
}

static int		valid_op(char op)
{
	return (op > 0 && op < 17);
}

static void		init_cycles(t_proc *p, unsigned char opcode)
{
	p->current_op = opcode;
	p->cycles++;
	p->cyclelimit = g_op_tab[opcode - 1].cycle_length;
}

void			process_execution(t_core *c, t_proc *process)
{
	char		op;
	int			oldpc;

	op = c->mem[process->pc % MEM_SIZE];
	oldpc = process->pc;
	if (process_is_waiting(process))
		process->cycles++;
	else
	{
		if (process->current_op == -1 && valid_op(op))
			init_cycles(process, op);
		else if (valid_op(process->current_op)
				&& process->cycles == process->cyclelimit)
		{
			op_execution(c, process);
			reinit_cycles(process);
		}
		else
			inc_pc(process, 1);
	}
	if (c->options & OPT_C)
		update_pc_ncurses(c, oldpc, process->pc);
}
