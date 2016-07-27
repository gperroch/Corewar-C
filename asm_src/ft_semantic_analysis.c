/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvalue_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahan <sdahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 16:47:11 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/15 11:09:15 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Calcul byte a partir du debut du code source jusqu'a la ligne courante
**	On fait la difference entre byte précédent et "byte" (byte entre debut et
**	le label a trouver
*/

static int	ft_getvalue_neg(t_list *line, t_list *current, int byte)
{
	int		byte_tmp;

	byte_tmp = 0;
	while (line)
	{
		if (line == current)
			return (byte - byte_tmp);
		byte_tmp = byte_tmp + ((t_line *)line->content)->nb_byte;
		line = line->next;
	}
	return (0);
}

static int	ft_getvalue_pos(t_list *current, t_list *target)
{
	int		byte;

	byte = 0;
	while (current)
	{
		if (current == target)
			break ;
		byte = byte + ((t_line *)current->content)->nb_byte;
		current = current->next;
	}
	return (byte);
}

/*
**	Cherche le label "target" dans le source puis lui associe ca valeur
**	cad ca position relative a l'instruction courante
*/

static int	ft_treat_label(t_list *line, t_list *current,
			t_token *token, char *target)
{
	int		len;
	int		bytes;
	t_list	*tmp;
	t_line	*content;

	bytes = 0;
	tmp = line;
	while (line)
	{
		len = ft_strlen(target);
		content = ((t_line *)line->content);
		if (content->islabel && ft_strncmp(content->data, target, len) == 0 &&
		content->data[len] == ':')
		{
			if (((t_line *)current->content)->number > content->number)
				token->value = ft_getvalue_neg(tmp, current, bytes);
			else
				token->value = ft_getvalue_pos(current, line);
			return (0);
		}
		bytes = bytes + content->nb_byte;
		line = line->next;
	}
	return (ft_perror_after(LABEL_NO_SUCH, target,
	((t_line *)current->content)->number));
}

/*
**	ASSOCIE une valeur aux tokens (analyse semantic)
*/

int			ft_getvalue_token(t_list *first_line, t_list *current)
{
	int		error;
	char	*target;
	t_list	*tokens;
	t_token	*content;

	error = 0;
	tokens = ((t_line *)current->content)->token;
	while (tokens)
	{
		content = ((t_token *)tokens->content);
		if (content->type == IND_CODE)
			content->value = ft_atoi(content->lexeme);
		else if (content->type == REG_CODE || content->type == DIR_CODE)
			content->value = ft_atoi(content->lexeme + 1);
		else if (content->type == DLABEL_CODE || content->type == ILABEL_CODE)
		{
			target = (content->type == ILABEL_CODE) ?
			content->lexeme + 1 : content->lexeme + 2;
			if (ft_treat_label(first_line, current, content, target) < 0)
				error = -1;
		}
		tokens = tokens->next;
	}
	return (error);
}
