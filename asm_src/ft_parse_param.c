/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:57:57 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/19 11:55:48 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Test si %:label ou :label
** Test si label est composer de LABEL_CHARS
*/

static int	ft_islabel_format(char *label, int line)
{
	int		i;

	if ((label[0] != DIRECT_CHAR && label[0] != LABEL_CHAR) ||
		(label[0] == DIRECT_CHAR && label[1] != LABEL_CHAR))
		return (ft_perror_after(FORMAT_LABEL, NULL, line));
	i = (label[0] == DIRECT_CHAR) ? 2 : 1;
	while (label[i])
	{
		if (!ft_strchr(LABEL_CHARS, label[i]))
			return (ft_perror_after(FORMAT_LABEL, NULL, line));
		i++;
	}
	return (TRUE);
}

/*
** Test que registre commence par "r"
** Apres "t" il y a des chiffres
** registre < REG_NUMBER && registre > -1
*/

static int	ft_isreg_format(char *reg, int line)
{
	int		value;

	if (reg[0] != REGISTER_CHAR)
		return (ft_perror_after(FORMAT_REG, NULL, line));
	if (!reg[1] || !ft_isstrdigit(&(reg[1])))
		return (ft_perror_after(OVERFLOW_REG, NULL, line));
	if ((value = ft_atoi(&reg[1])) > REG_NUMBER || value < 0)
		return (ft_perror_after(OVERFLOW_REG, NULL, line));
	return (0);
}

/*
**	Test que les differents type possibles sont bien former
*/

int			ft_parse_param(t_token *token, int line)
{
	int		i;

	if (token->type == REG_CODE)
		return (ft_isreg_format(token->lexeme, line));
	if (token->type == DLABEL_CODE || token->type == LABEL_CODE ||
		token->type == ILABEL_CODE)
		return (ft_islabel_format(token->lexeme, line));
	if (token->type == DIR_CODE)
	{
		i = (token->lexeme[1] == '-') ? 2 : 1;
		if (!ft_isstrdigit(&(token->lexeme[i])))
			return (ft_perror_after(SYNTAX_ERR_AF, "%", line));
	}
	return (0);
}

/*
**	Verifie que ce sont les bon parametres qui sont attendu
*/

int			ft_parse_type_param(t_line *line)
{
	int		i;
	int		tmp;
	t_token	*token;
	t_list	*tokens;

	if (line->op && ft_count_params(line->token) != line->op->nb_param)
		return (ft_perror_after(NB_PARAMS, line->op->name, line->number));
	i = 0;
	tokens = line->token->next;
	while (tokens)
	{
		tmp = -1;
		token = ((t_token *)tokens->content);
		if (token->type == REG_CODE)
			tmp = T_REG;
		else if (token->type == DLABEL_CODE || token->type == DIR_CODE)
			tmp = T_DIR;
		else if (token->type == ILABEL_CODE || token->type == IND_CODE)
			tmp = T_IND;
		if (line->op && (tmp & line->op->params[i]) != tmp)
			return (ft_perror_after(BAD_PARAM, token->lexeme, line->number));
		i++;
		tokens = tokens->next;
	}
	return (0);
}

/*
**	Test que les virgules sont bien placer (param separer par des virgules)
*/

int			ft_check_separator(char *str, int nb_param, int line)
{
	int		i;
	int		is_separate;
	int		count_separator;

	i = 0;
	is_separate = FALSE;
	count_separator = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == SEPARATOR_CHAR)
			return (ft_perror_after(SYNTAX_SEPARAT, NULL, line));
		else if (str[i] == SEPARATOR_CHAR)
		{
			count_separator++;
			if (is_separate)
				return (ft_perror_after(SYNTAX_SEPARAT, NULL, line));
			is_separate = TRUE;
		}
		else if (!ft_isspace(str[i]))
			is_separate = FALSE;
		i++;
	}
	if ((nb_param - 1) != count_separator)
		return (ft_perror_after(SYNTAX_SEPARAT, NULL, line));
	return (0);
}
