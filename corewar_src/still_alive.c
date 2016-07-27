/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   still_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:30:34 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/05 21:01:32 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				still_alive(t_core *c)
{
	t_list		*ptr_w;
	t_list		*ptr_p;
	t_warrior	*warrior;
	t_proc		*process;

	ptr_w = c->warriors;
	while (ptr_w)
	{
		warrior = (t_warrior *)ptr_w->content;
		ptr_p = warrior->procs;
		if (!ptr_p)
		{
			ptr_w = ptr_w->next;
			continue;
		}
		process = (t_proc *)ptr_p->content;
		if (process)
			return (1);
		ptr_w = ptr_w->next;
	}
	return (0);
}
