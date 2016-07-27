/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 10:57:33 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/10 18:05:58 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** function to securely write an int at a given address. Used for example in
** st and sti
*/

void	write_int(t_core *c, int color, int towrite, int addr)
{
	int		swapped;
	char	tab[4];
	int		i;

	swapped = int_swap(towrite);
	ft_memcpy(tab, &swapped, 4);
	i = 0;
	addr = modulo(addr, MEM_SIZE);
	while (i < 4)
	{
		c->mem[addr] = tab[i];
		c->memcolor[addr] = (char)color;
		if (c->options & OPT_C)
			write_at_ncurse(c, addr, color, tab[i]);
		addr = (addr + 1) % MEM_SIZE;
		i++;
	}
}
