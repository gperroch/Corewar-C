/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 16:59:32 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/03/07 10:23:44 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	ft_error(char *msg)
{
	if (msg)
	{
		ft_putstr_fd(msg, 2);
	}
}
