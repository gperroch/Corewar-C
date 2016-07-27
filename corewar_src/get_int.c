/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:49:13 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/04 10:17:25 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** function to get an int (4 bytes) value from memory. It increments the pc
*/

int		get_int(t_core *c, t_proc *p)
{
	char	nb[4];
	int		i;

	i = 0;
	while (i < 4)
	{
		nb[i] = c->mem[p->pc % MEM_SIZE];
		inc_pc(p, 1);
		i++;
	}
	return (int_swap(*(int *)nb));
}
