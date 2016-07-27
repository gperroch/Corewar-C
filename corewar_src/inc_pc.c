/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_pc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:39:55 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/04/29 13:08:35 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** function to securely increment the pc of a processus
*/

void	inc_pc(t_proc *p, int nb)
{
	if (!p)
		return ;
	p->pc = (p->pc + nb) % MEM_SIZE;
}
