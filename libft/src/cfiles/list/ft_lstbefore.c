/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbefore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:51:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/02/27 15:12:33 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
** function to get the node BEFORE the node in parameters
*/

t_list		*ft_lstbefore(t_list *start, const t_list *node)
{
	t_list	*ptr;

	if (!start || !node)
		return (NULL);
	ptr = start;
	while (ptr != NULL)
	{
		if (ptr->next == node)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}
