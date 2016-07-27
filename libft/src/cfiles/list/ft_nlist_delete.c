/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlist_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:50:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 11:28:26 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "mem.h"

void	ft_nlist_delete(t_nlist **list)
{
	ft_nlist_destroy(*list);
	ft_memdel((void **)list);
}
