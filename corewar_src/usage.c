/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:00:33 by gperroch          #+#    #+#             */
/*   Updated: 2016/05/11 16:01:13 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#define PFD(x) ft_putendl_fd(x, 2)

void			usage(void)
{
	ft_printf(
		"Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"
	"###################################################################\n"
	"-dump N    : Dump the memory at N cycles and exit the game.\n"
	"-s N       : Dump the memory every N cycles.\n"
	"###################################################################\n"
	"-v N       : Verbosity level (combination possible).\n"
	"           N = 1 : All operation\n"
	"               2 : process killing\n"
	"               3 : op live\n"
	"               4 : op add / sub\n"
	"               5 : op and / or/ xor\n"
	"               6 : op ld / ldi / lld / lldi\n"
	"               7 : op st / sti\n"
	"               8 : op fork / lfork / zjmp\n"
	"               9 : op aff\n"
	"###################################################################\n"
	"-c         : Display the game with nCurses.\n");
	exit(2);
}
