/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 10:06:29 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/28 10:51:13 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "mem.h"

/*
** Usage of cmp : for example, to sort integers in increasing orders, use
** int comp(const void *i, const void *j)
** {
** 		int a = *(int *)i;
**		int b = *(int *)j;
** 		return (a - b);
** }
** To sort strings in ASCII order, use
** int strcomp(const void *i, const void *j)
** {
**		char *a = *(char **)i;
**		char *b = *(char **)j;
**		return ft_strcmp(a, b);
** }
*/

void	ft_isort(void *data, size_t size, size_t esize, int (*cmp)())
{
	size_t	i;
	size_t	j;

	if (!data || !cmp)
		return ;
	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && cmp(data + (esize * (j - 1)), data + (esize * j)) > 0)
		{
			ft_memswap(data + ((j - 1) * esize), data + (j * esize), esize);
			j--;
		}
		i++;
	}
}
