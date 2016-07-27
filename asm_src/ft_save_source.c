/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 21:25:03 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/18 17:38:53 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>
#include <fcntl.h>

static int	ft_check_filename(char *name)
{
	int		length;

	length = ft_strlen(name);
	if (length >= 2 && name[length - 2] == '.' && name[length - 1] == 's')
		return (TRUE);
	return (FALSE);
}

static char	*ft_create_name(char *filename)
{
	char	*name;
	char	*tmp;

	tmp = ft_strrchr(filename, '.');
	*tmp = '\0';
	name = ft_strjoin(filename, ".cor");
	return (name);
}

static void	get_good_name(t_source *source, char *name)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strrchr(name, '/');
	if (tmp)
	{
		tmp[1] = '\0';
		tmp2 = ft_strjoin(name, source->name);
		free(source->name);
		source->name = tmp2;
		source->name = ft_strjoinf(&source->name, ".cor");
	}
	else
		source->name = ft_strjoinf(&source->name, ".cor");
}

int			ft_save_source(t_source *source, char *name)
{
	int		fd;

	if ((fd = ft_open(name, O_RDONLY)) == C_OPEN_FAILED)
		return (ft_strerror(C_OPEN_FAILED));
	if (!ft_check_filename(name))
	{
		close(fd);
		return (ft_strerror(C_BAD_EXT));
	}
	if (!source->name)
		source->name = ft_create_name(name);
	else
		get_good_name(source, name);
	if (ft_get_source(source, fd) < 0)
	{
		ft_free_source(source);
		return (-1);
	}
	if (!source->line)
	{
		ft_free_source(source);
		return (ft_strerror(C_EMPTY_FILE));
	}
	return (0);
}
