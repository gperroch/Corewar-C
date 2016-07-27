/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:50:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:28:26 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_nlist_addback(t_nlist *lst, t_list *elem)
{
	if (!lst || !elem)
		return (-1);
	return (ft_nlist_add(lst, lst->tail, elem));
}
