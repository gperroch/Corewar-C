/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bytecode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahan <sdahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 10:40:47 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/16 11:56:08 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Stock le codage de l'instruction : ld, sti, st, etc...
*/

static int	ft_get_opcode(t_line *line)
{
	if (!line->op)
		return (-1);
	line->bytecode[0] = line->op->op_number;
	return (0);
}

/*
**	Stock l'octet de codage des parametres si necessaire
*/

static int	ft_get_pcode(t_line *line)
{
	int		i;
	int		pcode;
	t_list	*tokens;
	t_token	*content;

	if (!line->op->ocp)
		return (0);
	i = 0;
	pcode = 0;
	tokens = line->token->next;
	while (tokens)
	{
		content = ((t_token *)tokens->content);
		if (content->type != REG_CODE)
			pcode = pcode | (1 << (7 - i));
		if (content->type == REG_CODE || content->type == IND_CODE ||
			content->type == ILABEL_CODE)
			pcode = pcode | (1 << (6 - i));
		i = i + 2;
		tokens = tokens->next;
	}
	line->bytecode[1] = pcode;
	return (0);
}

/*
**	Stock le codage de chaque parametres
*/

static void	ft_get_params_code(t_line *line, t_list *tokens, int i)
{
	int		size;
	t_token	*tmp;
	t_ui	value;

	while (tokens)
	{
		tmp = ((t_token *)tokens->content);
		value = uint_swap(tmp->value);
		if (tmp->type == REG_CODE)
		{
			size = 1;
			value = value >> 24;
		}
		else if ((tmp->type == DIR_CODE || tmp->type == DLABEL_CODE)
			&& !(line->op->carry_modif))
			size = 4;
		else
		{
			size = 2;
			value = value >> 16;
		}
		ft_memcpy(&line->bytecode[i], &(value), sizeof(value));
		i = i + size;
		tokens = tokens->next;
	}
}

/*
**	Creer le bytecode du source ligne par ligne
*/

int			ft_create_bytecode(t_source *source)
{
	t_line	*line;
	t_list	*cursor;
	t_ui	prog_size;

	cursor = source->line->next->next;
	while (cursor)
	{
		line = ((t_line *)cursor->content);
		if (line->islabel == FALSE)
		{
			ft_get_opcode(line);
			ft_get_pcode(line);
			ft_get_params_code(line, line->token->next,
			(line->op->ocp) ? 2 : 1);
		}
		cursor = cursor->next;
	}
	if ((prog_size = ft_get_progsize(source->line)) > CHAMP_MAX_SIZE)
	{
		ft_free_source(source);
		return (ft_strerror(C_SIZE_CHAMP));
	}
	source->header.prog_size = prog_size;
	return (0);
}
