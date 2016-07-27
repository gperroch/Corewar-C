/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:09:12 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/04/27 17:20:20 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		print_error(char *filename, int code)
{
	static const char	*msg[] = {
		"",
		"champion is too small",
		"champion is too big",
		"open failed",
		"read failed",
		"invalid champion",
		"no champions in memory",
		"too many champions in memory"
	};
	int					abscode;

	abscode = ABS(code);
	if (code > 7 || !filename)
		return (-1);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg[abscode], 2);
	return (-1);
}
