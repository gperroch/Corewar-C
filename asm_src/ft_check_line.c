/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:41:23 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/16 14:12:02 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_getlabel(char *line)
{
	int		i;
	int		j;
	char	*label;

	i = 0;
	label = NULL;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = i;
	while (line[j])
	{
		if (j > 0 && ft_isspace(line[j]) && line[j - 1] != LABEL_CHAR)
			return (FALSE);
		else if (j > 0 && line[j - 1] == LABEL_CHAR)
			break ;
		j++;
	}
	j--;
	label = ft_strndup(&(line[i]), j - i + 1);
	return (label);
}

int			ft_is_label_and_exec(char *line)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	j = i + 1;
	while (line[j])
	{
		if (ft_isspace(line[j]) && line[j - 1] != LABEL_CHAR)
			return (FALSE);
		else if (line[j - 1] == LABEL_CHAR)
			break ;
		j++;
	}
	if (!line[j])
		return (FALSE);
	while (line[j] && ft_isspace(line[j]))
		j++;
	if (!line[j])
		return (FALSE);
	return (TRUE);
}

int			ft_isempty_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			ft_iscomment_line(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			continue ;
		if (line[i] == COMMENT_CHAR || line[i] == COMMENT_CHAR_2)
			return (TRUE);
		else
			return (FALSE);
	}
	return (FALSE);
}
