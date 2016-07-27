/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_lexeme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahan <sdahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:39:46 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/10 22:27:03 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Essaye de reconnaitre les differents type admissible
**	(label, direct, indirect)
*/

int			ft_parse_type(char *lexeme, int index, int line)
{
	if (index == 0)
		return ((lexeme[ft_strlen(lexeme) - 1] == LABEL_CHAR) ?
		LABEL_CODE : OP_CODE);
	else if (lexeme[0] == DIRECT_CHAR)
		return ((lexeme[1] != LABEL_CHAR) ? DIR_CODE : DLABEL_CODE);
	else if (lexeme[0] == LABEL_CHAR)
		return (ILABEL_CODE);
	else if (lexeme[0] == REGISTER_CHAR)
		return (REG_CODE);
	else if ((lexeme[0] == '-' && ft_isstrdigit(&lexeme[1])) ||
		ft_isstrdigit(lexeme))
		return (IND_CODE);
	else
		return (ft_perror_after(UNKNOW_TOKEN, lexeme, line));
	return (0);
}

static t_op	*ft_getop_valid(char *opcode, int line)
{
	int		i;

	i = 0;
	while (g_optab[i].name)
	{
		if (ft_strcmp(g_optab[i].name, opcode) == 0)
			return ((t_op *)&(g_optab[i]));
		i++;
	}
	ft_perror_after(UNKNOW_OPCODE, opcode, line);
	return (NULL);
}

static int	ft_create_token(t_line *line, char *str, int size, int index)
{
	int		error;
	t_token	new_token;

	if (size <= 0)
		return (0);
	error = 0;
	ft_bzero(&new_token, sizeof(new_token));
	new_token.index = index;
	new_token.value = EMPTY;
	new_token.lexeme = ft_strndup(str, size);
	if ((new_token.type =
		ft_parse_type(new_token.lexeme, index, line->number)) < 0)
		error = -1;
	if (index == 0 && !(line->op =
		ft_getop_valid(new_token.lexeme, line->number)))
		error = -1;
	if (ft_parse_param(&new_token, line->number) < 0)
		error = -1;
	if (error >= 0)
		ft_lstadd_back(&(line->token), ft_lstnew(&new_token, sizeof(t_token)));
	return (error);
}

static int	ft_check_(t_line *line, int nb_token, int *error)
{
	if (ft_check_separator(line->data, ft_count_params(line->token),
		line->number) < 0)
		*error = -1;
	if (nb_token > MAX_ELEMENTS)
		*error = ft_perror_after(MANY_TOKEN, NULL, line->number);
	return (*error);
}

/*
**	SPLIT LIGNE PAR WORD ET LA SAUVEGARDE
*/

int			ft_check_lexeme(t_line *line)
{
	int		i;
	int		j;
	int		error;
	int		nb_token;
	int		max_tokens;

	i = 0;
	error = 0;
	nb_token = -1;
	max_tokens = MAX_ELEMENTS + 1;
	while (++nb_token < max_tokens)
	{
		while (line->data[i] && ft_isspace(line->data[i]))
			i++;
		j = i;
		while (line->data[j] && !ft_isspace(line->data[j]) &&
			line->data[j] != SEPARATOR_CHAR)
			j++;
		if (ft_create_token(line, &line->data[i], j - i, nb_token) < 0)
			error = -1;
		i = j + 1;
		if (!line->data[i - 1])
			break ;
	}
	return (ft_check_(line, nb_token, &error));
}
