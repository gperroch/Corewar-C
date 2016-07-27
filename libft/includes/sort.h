/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:52:34 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:32:07 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "list.h"

/*
** struct for qsort
*/

typedef struct		s_qsort
{
	int				esize;
	int				(*cmp)();
}					t_qsort;

/*
** sort tabs
*/

void				ft_isort(void *data, size_t size, size_t esize,
					int (*cmp)());
void				ft_qsort(void *data, size_t size, size_t esize,
					int (*cmp)());
void				ft_hsort(void *data, size_t size, size_t esize,
					int (*cmp)());

/*
** sort lists
*/

void				ft_lstsort(t_list **data, int (*cmp)());
void				ft_nlist_sort(t_nlist *lst, int (*cmp)());

/*
** compare funcs
*/

int					sort_str(const void *i, const void *k);
int					sort_int(const void *i, const void *k);

#endif
