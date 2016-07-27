/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_bytecode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:58:35 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/18 17:53:45 by sdahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>
#include <unistd.h>

static void	ft_write_file(void *mem, int size, int fd)
{
	int		i;
	char	*cursor;

	i = -1;
	cursor = (char *)mem;
	while (++i < size)
		ft_putchar_fd(cursor[i], fd);
}

static void	ft_write_header(t_header *header, int fd)
{
	header->magic = uint_swap(COREWAR_EXEC_MAGIC);
	header->prog_size = uint_swap(header->prog_size);
	ft_write_file(header, sizeof(t_header), fd);
}

static void	ft_write_code(t_list *line, int fd)
{
	t_line	*content;

	while (line)
	{
		content = ((t_line *)line->content);
		ft_write_file(content->bytecode, content->nb_byte, fd);
		line = line->next;
	}
}

int			ft_write_bytecode(t_source *source)
{
	int		fd;

	if ((fd = ft_open(source->name, O_RDWR | O_CREAT | O_TRUNC)) == -1)
	{
		ft_free_source(source);
		return (ft_strerror(C_CREATE_FAIL));
	}
	ft_write_header(&(source->header), fd);
	ft_write_code(source->line, fd);
	close(fd);
	if (!(g_color & OPT_C))
		ft_pcolor(OK_WRITE, source->name, GREEN);
	else
	{
		ft_putstr(OK_WRITE);
		ft_putchar(' ');
		ft_putendl(source->name);
	}
	ft_free_source(source);
	return (0);
}
