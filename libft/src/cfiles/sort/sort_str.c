/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 17:48:13 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/28 10:43:35 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/*
** func for sort functions to sort strings by ASCII order in isort
*/

int	sort_str(const void *i, const void *j)
{
	char	*a;
	char	*b;

	a = *(char **)i;
	b = *(char **)j;
	return (ft_strcmp(a, b));
}
