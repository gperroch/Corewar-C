/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ_by_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:37:55 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/09 17:39:14 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** function to, during a live, ge tthe name of the champ that is described
** as alive by the parameter of the live instruction
*/

t_warrior	*get_champ_by_nb(t_core *c, int nb)
{
	t_list		*ptr;

	if (!c || !c->warriors)
		return (NULL);
	ptr = c->warriors;
	while (ptr != NULL)
	{
		if (ptr->content)
		{
			if (((t_warrior *)ptr->content)->number == nb)
				return (((t_warrior *)ptr->content));
		}
		ptr = ptr->next;
	}
	return (NULL);
}
