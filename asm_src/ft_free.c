/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 19:49:44 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/12 15:33:35 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	FREE - STEP LEXICAL ANALYSIS
*/

static void	ft_free_token(t_list *line)
{
	t_list	*tmp;
	t_list	*cursor;
	t_token	*content;

	cursor = ((t_line *)line->content)->token;
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
		content = (t_token *)tmp->content;
		ft_memdel((void**)&(content->lexeme));
		ft_memdel((void**)&(content));
		ft_memdel((void**)&tmp);
	}
}

/*
**	FREE - STEP SAVE SOURCE
*/

void		ft_free_source(t_source *source)
{
	t_list	*tmp;
	t_list	*cursor;
	t_line	*content;

	cursor = source->line;
	ft_memdel((void**)&source->name);
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
		content = (t_line *)tmp->content;
		ft_memdel((void**)&(content->data));
		if (((t_line *)tmp->content)->token)
			ft_free_token(tmp);
		ft_memdel((void**)&(content));
		ft_memdel((void**)&tmp);
	}
}

void		ft_free_list_args(t_args **arg)
{
	t_args	*tmp;

	if (!*arg)
		return ;
	while (*arg)
	{
		tmp = *arg;
		free((*arg)->filename);
		free((*arg)->newname);
		(*arg) = (*arg)->next;
		free(tmp);
	}
	free(*arg);
}
