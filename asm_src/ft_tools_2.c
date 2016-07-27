/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:38:05 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/15 16:13:12 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_strjoinf(char **s1, char const *s2)
{
	char	*join;

	if ((join = ft_strnew(ft_strlen(*s1) + ft_strlen(s2))))
	{
		join = ft_strcpy(join, *s1);
		join = ft_strcat(join, s2);
		ft_memdel((void**)s1);
	}
	return (join);
}

void	ft_putstrc(int color, int background, char *str)
{
	if (color >= 0 && color <= 7)
	{
		ft_putstr("\033[");
		ft_putnbr(color + 30);
		if (background >= 0 && background <= 7)
		{
			ft_putstr(";");
			ft_putnbr(background + 40);
		}
		ft_putstr("m");
		ft_putstr(str);
		ft_putstr(DEFAULT);
	}
}

/*
**	0 : noir ;
**	1 : rouge ;
**	2 : vert ;
**	3 : jaune ;
**	4 : bleu ;
**	5 : rose ;
**	6 : cyan ;
** 	7 : gris.
*/

void	ft_align_text(int len, int offset)
{
	while (len++ < LEN_TAB - offset)
		ft_printf(" ");
}
