/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:37:39 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/02/12 11:48:31 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strtabfree(char **tab)
{
	char	**ptr;

	if (!tab)
		return ;
	ptr = tab;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(tab);
}
