/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 09:54:06 by gperroch          #+#    #+#             */
/*   Updated: 2016/05/13 09:06:19 by gperroch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_tabjoin_str(char ***tab, int length, char *str)
{
	int		nb;
	int		i;
	char	**new_tab;

	nb = (length >= 0) ? length : 0;
	i = -1;
	new_tab = NULL;
	if (!str)
		return (NULL);
	if (*tab && length < 0)
	{
		while ((*tab)[nb])
			nb++;
	}
	if (!*tab)
		nb = 0;
	if (!(new_tab = (char**)malloc(sizeof(char*) * (nb + 2))))
		return (NULL);
	new_tab[nb] = ft_strdup(str);
	new_tab[nb + 1] = NULL;
	while (++i < nb)
		new_tab[i] = ft_strdup((*tab)[i]);
	ft_strtabfree(*tab);
	*tab = new_tab;
	return (new_tab);
}
