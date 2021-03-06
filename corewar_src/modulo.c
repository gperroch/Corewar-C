/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:52:15 by gperroch          #+#    #+#             */
/*   Updated: 2016/05/11 16:02:11 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		modulo(int a, int b)
{
	int		ret;

	ret = a % b;
	if (ret < 0)
		ret += b;
	return (ret);
}
