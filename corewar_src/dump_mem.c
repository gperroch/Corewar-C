/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 11:57:18 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/09 17:03:01 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include <unistd.h>

void		dump_mem(t_core *c)
{
	int		i;
	int		addr;

	i = 0;
	addr = 0;
	while (i < MEM_SIZE)
	{
		if (i == 0 || i % 32 == 0)
			ft_printf("0x%05x ", i);
		ft_putstr(g_colors[(int)c->memcolor[addr]]);
		ft_printf("%02hhx", c->mem[addr]);
		ft_putstr("\033[0m");
		addr++;
		i++;
		write(1, " ", 1);
		if (i % 32 == 0 || i == MEM_SIZE)
			write(1, "\n", 1);
	}
}
