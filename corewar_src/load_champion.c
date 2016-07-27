/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:01:36 by tpaulmye          #+#    #+#             */
/*   Updated: 2016/05/11 16:00:21 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>
#include <unistd.h>

static int			champion_is_valid(t_header *h, size_t size)
{
	return ((h->magic == COREWAR_MAGIC_LE) && (h->prog_size > 0)
			&& (h->prog_size <= CHAMP_MAX_SIZE)
			&& (size - sizeof(*h) == h->prog_size));
}

static int			create_champion(t_warrior *w, char *buf, int nb,
					size_t size)
{
	t_header	header;

	if (size <= sizeof(header))
		return (CHAMP_TOO_SMALL);
	ft_memcpy(&header, buf, sizeof(header));
	header.prog_size = int_swap(header.prog_size);
	if (!champion_is_valid(&header, size))
		return (INVALID_CHAMP);
	ft_bzero(w, sizeof(*w));
	ft_memcpy(w->name, header.prog_name, PROG_NAME_LENGTH);
	ft_memcpy(w->comment, header.comment, COMMENT_LENGTH);
	w->size = header.prog_size;
	ft_memcpy(w->code, buf + sizeof(t_header), header.prog_size);
	w->number = nb;
	return (0);
}

int					load_champion(t_core *c, char *file, int nb, int color)
{
	int			fd;
	int			rfd;
	char		buf[BUFSIZE + 1];
	t_warrior	w;
	int			ret;

	if (!file || ((fd = open(file, O_RDONLY)) == -1))
		return (OPEN_FAILED);
	if ((rfd = read(fd, buf, BUFSIZE + 1)) < 0)
	{
		close(fd);
		return (READ_FAILED);
	}
	else if (rfd > BUFSIZE)
	{
		close(fd);
		return (CHAMP_TOO_BIG);
	}
	buf[rfd] = '\0';
	close(fd);
	if ((ret = create_champion(&w, buf, nb, rfd)) < 0)
		return (ret);
	w.color = color;
	ft_lstadd(&c->warriors, ft_lstnew(&w, sizeof(w)));
	return (0);
}
