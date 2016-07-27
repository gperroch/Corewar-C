/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:56:01 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 16:19:17 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		init_proc(t_warrior *w, int pc)
{
	t_proc		p;
	int			i;

	if (!w)
		return (-1);
	ft_bzero(&p, sizeof(p));
	p.pc = pc;
	p.regs[0] = w->number;
	i = 1;
	while (i < REG_NUMBER)
	{
		p.regs[i] = 0;
		i++;
	}
	p.owner = w;
	p.current_op = -1;
	p.cycles = 1;
	p.color = w->color;
	ft_lstadd(&w->procs, ft_lstnew(&p, sizeof(p)));
	w->nbprocs++;
	return (0);
}
