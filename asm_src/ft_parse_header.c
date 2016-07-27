/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahan <sdahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:38:07 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/18 17:26:51 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Check le .name et l' "analyse syntaxique" test qu'un suit bien
**	Test si name est border de ""
**		 si la taille maximale est bonne
**	=> Copie le resultat dans la structure header
*/

static int	ft_parse_name(t_header *header, char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(NAME_CMD_STRING);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != '"')
		return (ft_strerror(C_SYNTAX_NAME));
	i++;
	j = i;
	while (line[j] && line[j] != '"')
		j++;
	if (line[j] != '"' || line[j + 1])
		return (ft_strerror(C_SYNTAX_NAME));
	if ((j - i) <= 0)
		return (0);
	tmp = ft_strndup(&(line[i]), j - i);
	if (ft_strlen(tmp) > PROG_NAME_LENGTH)
		return (ft_strerror(C_SIZE_NAME));
	ft_memcpy(header->prog_name, tmp, ft_strlen(tmp));
	ft_memdel((void**)&tmp);
	return (0);
}

int			ft_parse_comment(t_header *header, char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(COMMENT_CMD_STRING);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] != '"')
		return (ft_strerror(C_SYNTAX_COM));
	i++;
	j = i;
	while (line[j] && line[j] != '"')
		j++;
	if (line[j] != '"' || line[j + 1])
		return (ft_strerror(C_SYNTAX_COM));
	if ((j - i) <= 0)
		return (0);
	tmp = ft_strndup(&(line[i]), j - i);
	if (ft_strlen(tmp) > COMMENT_LENGTH)
		return (ft_strerror(C_SIZE_COMMENT));
	ft_memcpy(header->comment, tmp, ft_strlen(tmp));
	ft_memdel((void**)&tmp);
	return (0);
}

static char	*ft_isname(t_list *line)
{
	if (!line)
		return (NULL);
	if (ft_strncmp(((t_line *)line->content)->data, NAME_CMD_STRING,
		ft_strlen(NAME_CMD_STRING)) == 0)
		return ((t_line *)line->content)->data;
	return (NULL);
}

static char	*ft_iscomment(t_list *line)
{
	if (!line)
		return (NULL);
	if (ft_strncmp(((t_line *)line->content)->data, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)) == 0)
		return ((t_line *)line->content)->data;
	return (NULL);
}

int			ft_parse_header(t_source *source)
{
	char	*tmp;
	int		error;
	t_list	*line_2;

	error = 0;
	tmp = NULL;
	line_2 = source->line->next;
	tmp = ft_isname(source->line);
	tmp = (!tmp) ? ft_isname(line_2) : tmp;
	error = (!tmp) ? ft_strerror(C_MISS_NAME) : error;
	if (tmp && ft_parse_name(&(source->header), tmp) < 0)
		error = -1;
	tmp = NULL;
	tmp = ft_iscomment(source->line);
	tmp = (!tmp) ? ft_iscomment(line_2) : tmp;
	error = (!tmp) ? ft_strerror(C_MISS_COMMENT) : error;
	if (tmp && ft_parse_comment(&(source->header), tmp) < 0)
		error = -1;
	return (error);
}
