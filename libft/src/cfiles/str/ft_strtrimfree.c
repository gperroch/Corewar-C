/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:58:03 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/02/18 17:05:10 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/*
** Trim the line, and also free the old untrimmed line
*/

char		*ft_strtrimfree(char **s)
{
	char	*ptr;

	if (!s || !*s)
		return (NULL);
	ptr = ft_strtrim(*s);
	ft_strdel(s);
	return (ptr);
}
