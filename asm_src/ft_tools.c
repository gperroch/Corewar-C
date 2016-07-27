/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahan <sdahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:08:05 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/12 13:33:30 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

int			ft_open(const char *name, int mode)
{
	int		fd;

	if ((fd = open(name, mode, 0655)) != -1)
		return (fd);
	return (C_OPEN_FAILED);
}

int			ft_isstrdigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

size_t		ft_count_params(t_list *tokens)
{
	size_t	i;

	if (!tokens)
		return (0);
	i = -1;
	while (tokens)
	{
		i++;
		tokens = tokens->next;
	}
	return (i);
}

t_ui		ft_get_progsize(t_list *line)
{
	t_ui	bytes;

	bytes = 0;
	while (line)
	{
		bytes = bytes + ((t_line *)line->content)->nb_byte;
		line = line->next;
	}
	return (bytes);
}

t_ui		uint_swap(t_ui nb)
{
	nb = ((nb << 8) & 0xFF00FF00) | ((nb >> 8) & 0xFF00FF);
	nb = ((nb << 16) | (nb >> 16));
	return (nb);
}
