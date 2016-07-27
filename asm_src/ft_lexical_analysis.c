/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexical_analysis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahan <sdahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:54:23 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/18 16:21:15 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_getnb_byte(t_line *line)
{
	t_token	*tmp;
	t_list	*tokens;

	if (!line->op || !line->token)
		return ;
	line->nb_byte = 1;
	tokens = line->token->next;
	if (line->op->ocp)
		(line->nb_byte)++;
	while (tokens)
	{
		tmp = ((t_token *)tokens->content);
		if (tmp->type == REG_CODE)
			line->nb_byte = line->nb_byte + 1;
		else if ((tmp->type == DIR_CODE || tmp->type == DLABEL_CODE)
			&& !(line->op->carry_modif))
			line->nb_byte = line->nb_byte + 4;
		else
			line->nb_byte = line->nb_byte + 2;
		tokens = tokens->next;
	}
}

static int	ft_analysis_source(t_list *cursor)
{
	int		tmp;
	int		error;

	error = 0;
	while (cursor)
	{
		if (!((t_line *)cursor->content)->islabel)
		{
			if ((tmp = ft_check_lexeme((t_line *)cursor->content)) > -1)
			{
				if (ft_parse_type_param((t_line *)cursor->content) < 0)
					error = -1;
				if (error > -1)
					ft_getnb_byte((t_line *)cursor->content);
			}
			else
				error = tmp;
		}
		cursor = cursor->next;
	}
	return (error);
}

static int	ft_check_labname(char *label, int line)
{
	int		i;

	i = 0;
	while (label[i])
	{
		if (label[i] == LABEL_CHAR)
		{
			i++;
			break ;
		}
		if (!ft_strchr(LABEL_CHARS, label[i]))
			return (ft_perror_after(FORMAT_LABEL, NULL, line));
		i++;
	}
	if (label[i])
		return (ft_perror_after(FORMAT_LABEL, NULL, line));
	return (TRUE);
}

static int	ft_analysis_label(t_list *line, t_list *cursor)
{
	int		error;

	error = 0;
	while (cursor)
	{
		if (!((t_line *)cursor->content)->islabel)
		{
			if (ft_getvalue_token(line, cursor) < 0)
				error = -1;
		}
		else
		{
			if (ft_check_labname(((t_line *)cursor->content)->data,
				((t_line *)cursor->content)->number) < 0)
				error = -1;
		}
		cursor = cursor->next;
	}
	return (error);
}

/*
**	Verifie que les choses sont bien former
**	Verifie que les mots existent vraiment
*/

int			ft_lexical_analysis(t_source *source)
{
	int		error;

	if (ft_parse_header(source) < 0)
		return (-1);
	if (!source->line->next->next)
	{
		ft_free_source(source);
		return (ft_strerror(C_NO_INSTRUCT));
	}
	error = ft_analysis_source(source->line->next->next);
	if (error < 0)
		ft_free_source(source);
	else if (ft_analysis_label(source->line, source->line->next->next) < 0)
		error = -1;
	return (error);
}
