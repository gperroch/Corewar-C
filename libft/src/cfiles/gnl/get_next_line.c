/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 11:27:59 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:40:52 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "str.h"
#include <unistd.h>
#include <stdlib.h>

void		str_file(char **file, char *buffer, int *fd_read)
{
	char	*tmp;

	if (*file == 0)
	{
		if ((tmp = ft_strnew((*fd_read) * sizeof(char))) == NULL)
			return ;
		ft_strcpy(tmp, buffer);
	}
	else
	{
		tmp = ft_strnew((ft_strlen(*file) + *fd_read) * sizeof(char));
		if (tmp == 0)
			return ;
		ft_strcpy(tmp, *file);
		ft_strcat(tmp, buffer);
		ft_strdel(file);
	}
	*file = tmp;
}

void		adjust_file(char **file)
{
	char	*adjusted_file;
	char	*ptr_file;

	ptr_file = *file;
	while (**file != '\n' && **file != 0)
		(*file)++;
	if ((*file) + 1 == '\0')
		return ;
	else
		(*file)++;
	adjusted_file = ft_strnew(ft_strlen(*file) * sizeof(**file));
	if (adjusted_file == 0)
		return ;
	ft_strcpy(adjusted_file, *file);
	ft_strdel(&ptr_file);
	*file = adjusted_file;
}

size_t		size_line(char *file)
{
	size_t	size;

	size = 0;
	while (file[size] != '\n' && file[size] != '\0')
		size++;
	return (size);
}

char		*parse_line(char *file)
{
	char	*ptr_line;

	if (size_line(file) == 0)
	{
		if ((ptr_line = (char *)malloc(1)) == NULL)
			return (0);
		ptr_line[0] = '\0';
		return (ptr_line);
	}
	else
	{
		ptr_line = ft_strnew((size_line(file)) * sizeof(*file));
		if (ptr_line == 0)
			return (0);
		ft_strncpy(ptr_line, file, size_line(file));
		ptr_line[size_line(file)] = '\0';
		return (ptr_line);
	}
}

int			get_next_line(int const fd, char **line)
{
	char		*buffer;
	int			fd_read;
	static char	*file = 0;
	static int	boucle = 1;

	if (!(buffer = ft_strnew((BUFF_SIZE) * sizeof(*buffer))) || !line)
		return (-1);
	while ((fd_read = read(fd, buffer, BUFF_SIZE)) || boucle || (file && *file))
	{
		if (fd_read == -1 || (fd_read == 0 && file == 0))
			return (fd_read);
		boucle = 0;
		buffer[fd_read] = '\0';
		str_file(&file, buffer, &fd_read);
		if (ft_strchr(file, '\n') != NULL || (fd_read < BUFF_SIZE))
		{
			*line = parse_line(file);
			adjust_file(&file);
			ft_strdel(&buffer);
			return (1);
		}
	}
	ft_strdel(&buffer);
	ft_strdel(&file);
	return (0);
}

/*
** function str_file is used to create a string containing what is read by
** the buffer. if such a string already exists, it copies it in a new string,
** add what the buffer read with ft_strcat, and free the old string.
*/

/*
** function adjust_file is used after parse_file to find the next occurrence
** of a \n in the string file and adjust the pointer just after it except if the
** function stumble on a \0, then it returns 0. after that, it creates a
** fresh "adjusted string" and free the original string contained in
** ptr_file.
*/

/*
** size_line just calculate the length of a string until a \n or a \0.
*/

/*
** parse_line returns the line that will be printed by the main.c. if size_line
** equal 0, meaning if a line is just a \n, it sends back a "\0" string.
** otherwise, it copies the line file in ptr_line, ends it with a \0, and
** returns it. it is actually the "next line".
*/
