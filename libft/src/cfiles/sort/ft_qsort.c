/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 10:06:29 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/28 10:51:13 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "mem.h"
#include <stdlib.h>

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

static void		*median(t_qsort *q, void *data, int pleft, int pright)
{
	void	*t[3];
	int		i;
	void	*tmp;

	t[0] = data + (q->esize * pleft);
	t[1] = data + (q->esize * ((pright + pleft) / 2));
	t[2] = data + (q->esize * (pright));
	i = 1;
	while (i < 3)
	{
		if (q->cmp(t[i - 1], t[i]) > 0)
		{
			tmp = t[i - 1];
			t[i - 1] = t[i];
			t[i] = tmp;
			i = 0;
		}
		i++;
	}
	return (t[1]);
}

static int		partition(t_qsort *q, void *data, int low, int high)
{
	void	*bernard;
	void	*pivot;

	bernard = median(q, data, low, high);
	if (!(pivot = malloc(q->esize)))
		return (-1);
	ft_memcpy(pivot, bernard, q->esize);
	low--;
	high++;
	while (low < high)
	{
		high--;
		while (q->cmp(data + (high * q->esize), pivot) > 0)
			high--;
		low++;
		while (q->cmp(data + (low * q->esize), pivot) < 0)
			low++;
		if (low < high)
		{
			ft_memswap(data + (low * q->esize), data + (high * q->esize),
							q->esize);
		}
	}
	free(pivot);
	return (high);
}

static void		quicksort_(t_qsort *q, void *data, int low, int high)
{
	int		middle;

	if (low >= high)
		return ;
	middle = partition(q, data, low, high);
	if (middle < 0)
		return ;
	quicksort_(q, data, low, middle);
	quicksort_(q, data, middle + 1, high);
}

void			ft_qsort(void *data, size_t size, size_t esize, int (*cmp)())
{
	t_qsort	q;

	q.esize = (int)esize;
	q.cmp = cmp;
	quicksort_(&q, data, 0, size - 1);
}
