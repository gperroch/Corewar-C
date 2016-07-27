/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_source.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:49:35 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/15 11:28:14 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>

static void	ft_save_line(t_list **line, char *str, int number_line)
{
	char	*tmp;
	t_line	new_line;

	if (ft_iscomment_line(str))
		return ;
	ft_bzero(&new_line, sizeof(t_line));
	new_line.number = number_line;
	ft_bzero(new_line.bytecode, 16);
	if ((tmp = ft_strchr(str, COMMENT_CHAR_2)))
		*tmp = '\0';
	if ((tmp = ft_strchr(str, COMMENT_CHAR)))
		*tmp = '\0';
	new_line.data = ft_strtrim(str);
	new_line.islabel = (new_line.data[ft_strlen(new_line.data) - 1] == ':')
	? TRUE : FALSE;
	ft_lstadd_back(line, ft_lstnew(&new_line, sizeof(t_line)));
}

static int	ft_getbody_source(t_source *source, int fd, int nb_line)
{
	int		ret;
	char	*line;
	char	*label;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_isempty_line(line) || ft_iscomment_line(line))
		{
			nb_line++;
			ft_memdel((void**)&line);
			continue ;
		}
		if (ft_is_label_and_exec(line) && (label = ft_getlabel(line)))
		{
			ft_save_line(&(source->line), label, ++nb_line);
			ft_save_line(&(source->line), ft_strchr(line, ':') + 1, nb_line);
			ft_memdel((void**)&label);
		}
		else
			ft_save_line(&(source->line), line, ++nb_line);
		ft_memdel((void**)&line);
	}
	close(fd);
	return ((ret < -1) ? ft_strerror(C_READ) : 0);
}

static int	ft_isend_gnl(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i] && tmp[i] != '"')
		i++;
	if (!tmp[i])
		return (FALSE);
	i++;
	while (tmp[i] && tmp[i] != '"')
		i++;
	if (!tmp[i])
		return (FALSE);
	return (TRUE);
}

static char	*ft_(t_source *source, char *tmp, int nb_line, int *i)
{
	(*i)++;
	ft_save_line(&(source->line), tmp, nb_line);
	ft_memdel((void**)&tmp);
	return (ft_strnew(1));
}

int			ft_get_source(t_source *source, int fd)
{
	int		i;
	int		ret;
	char	*tmp;
	char	*line;
	int		nb_line;

	i = 0;
	nb_line = 1;
	tmp = ft_strnew(1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (tmp[0] || (!ft_isempty_line(line) && !ft_iscomment_line(line)))
		{
			tmp = ft_strjoinf(&tmp, line);
			tmp = ft_isend_gnl(tmp) ? ft_(source, tmp, nb_line, &i) :
			ft_strjoinf(&tmp, "\n");
		}
		ft_memdel((void**)&line);
		if (i > 1)
			break ;
		nb_line++;
	}
	ft_memdel((void**)&tmp);
	return (ret == -1) ? (ft_strerror(C_READ)) :
	ft_getbody_source(source, fd, nb_line);
}
