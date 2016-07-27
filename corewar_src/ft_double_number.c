/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:58:26 by gperroch          #+#    #+#             */
/*   Updated: 2016/04/27 16:00:11 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_double_number(int *champ_numbers, int nb_champ)
{
	int		i;
	int		j;

	i = -1;
	while (++i < nb_champ)
	{
		j = i;
		while (++j < nb_champ)
			if (champ_numbers[i] == champ_numbers[j])
				usage();
	}
}
