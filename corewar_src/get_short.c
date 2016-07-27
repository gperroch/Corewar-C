/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:49:13 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/04 10:17:30 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** function to get a short (2 bytes) value from memory. It increments the pc
*/

short	get_short(t_core *c, t_proc *p)
{
	char	nb[2];
	int		i;

	i = 0;
	while (i < 2)
	{
		nb[i] = c->mem[p->pc % MEM_SIZE];
		inc_pc(p, 1);
		i++;
	}
	return (short_swap(*(short *)nb));
}
