/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:38:31 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/09 17:10:44 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Effectue les operations requises sur la memoire;
**	Modifie le carry et/ou le PC (+1 sans saut, +x avec saut);
**	Redefinie process->cyclelimit en fonction de la nouvelle
**	zone memoire pointee par le PC;
**	Avance le PC en fonction de l'encodage des parametres.
*/

void			op_execution(t_core *c, t_proc *process)
{
	int			i;
	int			op_addr;

	i = 0;
	op_addr = process->pc % MEM_SIZE;
	inc_pc(process, 1);
	while (i < 16)
	{
		if (g_op_function[i].op_number == process->current_op)
		{
			g_op_function[i].f(c, process, op_addr);
			return ;
		}
		i++;
	}
}
