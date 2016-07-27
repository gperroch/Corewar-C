/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_from.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:49:13 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/04 13:26:15 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** function to get an int (4 bytes) value from a particular address (addr
** parameter. It DOES NOT increments the pc. Unsed for example in ldi and lldi
*/

int		get_int_from(t_core *c, int addr)
{
	char	nb[4];
	int		i;

	i = 0;
	while (i < 4)
	{
		nb[i] = c->mem[addr % MEM_SIZE];
		addr++;
		i++;
	}
	return (int_swap(*(int *)nb));
}
