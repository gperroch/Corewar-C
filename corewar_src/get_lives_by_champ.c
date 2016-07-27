/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lives_by_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:49:31 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 16:58:05 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_lives_by_champ(t_core *c, int nb)
{
	size_t	i;

	i = 0;
	while (i < c->nb_warriors)
	{
		if (c->warriors_numbers[i] == nb)
		{
			return (c->lives_tmp[i]);
		}
		i++;
	}
	return (-1);
}
