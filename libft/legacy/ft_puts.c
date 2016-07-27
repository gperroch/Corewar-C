/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:32:26 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/02/12 11:37:34 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <unistd.h>

int		ft_puts(const char *s)
{
	int		ret;

	if (!s)
		return (write(STDOUT_FILENO, "(null)\n", 7));
	ret = write(STDOUT_FILENO, s, ft_strlen(s));
	if (ret < 0)
		return (ret);
	if (write(STDOUT_FILENO, "\n", 1) < 0)
		return (-1);
	return (ret + 1);
}
