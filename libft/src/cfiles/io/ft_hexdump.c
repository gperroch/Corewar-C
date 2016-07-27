/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:41:51 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/03/17 13:46:05 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "ft_ctypes.h"
#include <stdlib.h>
#include <unistd.h>

void			ft_hexdump(void *offset, size_t size, int digit)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)offset;
	while (i < size)
	{
		if (ft_isprint(*ptr) && digit)
			ft_printf(" %c", *ptr++);
		else
			ft_printf("%02hhx", *ptr++);
		i++;
		write(1, " ", 1);
		if (i % 16 == 0 || i == size)
			write(1, "\n", 1);
	}
}
