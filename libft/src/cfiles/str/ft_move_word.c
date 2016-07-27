/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 17:04:46 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/07/20 17:05:06 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctypes.h"

char		*ft_move_word(char *line)
{
	char	*ret;

	if (!line || !*line)
		return (0);
	ret = line;
	while (*ret && !ft_isspace(*ret))
		ret++;
	if (!*ret)
		return (0);
	while (*ret && ft_isspace(*ret))
		ret++;
	if (!*ret)
		return (0);
	return (ret);
}
