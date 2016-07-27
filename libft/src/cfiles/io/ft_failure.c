/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_failure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 16:59:32 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/07/20 17:02:27 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "io.h"

void	ft_failure(void *alloc, char *msg)
{
	if (alloc == NULL)
	{
		ft_error(msg);
		exit(1);
	}
}
