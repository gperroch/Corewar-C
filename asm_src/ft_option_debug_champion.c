/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_debug_champion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:57:02 by pilespin          #+#    #+#             */
/*   Updated: 2016/05/15 16:37:22 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

static void	ft_put_token_lexeme(t_list *tmp, t_list *cursor)
{
	int			i;
	int			len;
	static int	s = 0;

	i = -1;
	while (tmp)
	{
		if (!++i)
		{
			len = ft_printf("%s", ft_itoa(s));
			s += (((t_line *)cursor->content)->nb_byte);
			ft_align_text(len, 0);
			len = ft_strlen(((t_token *)tmp->content)->lexeme);
			ft_putstrc(6, 0, ((t_token *)tmp->content)->lexeme);
			ft_align_text(len, 0);
		}
		else
		{
			len = ft_strlen(((t_token *)tmp->content)->lexeme);
			ft_putstrc(1, 0, ((t_token *)tmp->content)->lexeme);
			ft_align_text(len, 0);
		}
		tmp = tmp->next;
	}
	ft_printf("\n");
}

static void	ft_put_token_value(t_list *tmp)
{
	int len;

	if (tmp)
		tmp = tmp->next;
	while (tmp)
	{
		len = ft_printf("%d", ((t_token *)tmp->content)->value);
		ft_align_text(len, 0);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

static void	ft_putheader_debug(t_source *source)
{
	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size  :  %d bytes\n", ft_get_progsize(source->line));
	ft_printf("Name          :  \"%s\"\n", source->header.prog_name);
	ft_printf("Comment       :  \"%s\"\n\n", source->header.comment);
}

void		ft_option_debug_champion(t_source *source)
{
	t_list	*cursor;
	int		l;

	ft_putheader_debug(source);
	cursor = source->line;
	while (cursor)
	{
		if (((t_line *)cursor->content)->islabel)
		{
			ft_putstrc(0, 3, ((t_line *)cursor->content)->data);
			ft_putchar('\n');
		}
		if (((t_line *)cursor->content)->token)
		{
			ft_put_token_lexeme(((t_line *)cursor->content)->token, cursor);
			l = 0;
			ft_align_text(l, 0);
			l = ft_printf("%do", (((t_line *)cursor->content)->nb_byte));
			ft_align_text(l, 0);
			ft_put_token_value(((t_line *)cursor->content)->token);
		}
		cursor = cursor->next;
	}
	ft_free_source(source);
}
