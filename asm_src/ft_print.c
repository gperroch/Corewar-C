/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 23:43:22 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/14 18:33:24 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_list_arg(t_args *arg)
{
	while (arg)
	{
		ft_printf("file: \"%s\" rename: \"%s\"\n", arg->filename, arg->newname);
		arg = arg->next;
	}
}

int		ft_strerror(int code)
{
	static const char *msg[] = {
		"",
		M_OPEN_FAILED,
		M_BAD_EXT,
		M_MALLOC,
		M_READ,
		M_MISS_NAME,
		M_MISS_COMMENT,
		M_SYNTAX_NAME,
		M_SYNTAX_COM,
		M_SIZE_NAME,
		M_SIZE_COMMENT,
		M_EMPTY_FILE,
		M_SIZE_CHAMP,
		M_CREATE_FAIL,
		M_NO_INSTRUCT
	};

	ft_perror((char *)msg[ABS(code)]);
	return (code);
}

void	ft_perror(char *error)
{
	if (!(g_color & OPT_C))
		ft_putstr_fd(RED, 2);
	ft_putstr_fd("✗ ", 2);
	if (!(g_color & OPT_C))
		ft_putstr_fd(RED_LIGHT, 2);
	ft_putendl_fd(error, 2);
	if (!(g_color & OPT_C))
		ft_putstr_fd(DEFAULT, 2);
}

/*
** Line X : error after
*/

int		ft_perror_after(char *error, char *after, int line)
{
	if (!(g_color & OPT_C))
		ft_putstr_fd(RED, 2);
	ft_putstr_fd("✗ ", 2);
	if (!(g_color & OPT_C))
		ft_putstr_fd(RED_LIGHT, 2);
	ft_putstr_fd("ligne ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(" : ", 2);
	if (after)
	{
		ft_putstr_fd(error, 2);
		ft_putstr_fd(" \"", 2);
		ft_putstr_fd(after, 2);
		ft_putendl_fd("\" ", 2);
	}
	else
		ft_putendl_fd(error, 2);
	if (!(g_color & OPT_C))
		ft_putstr_fd(DEFAULT, 2);
	return (-1);
}

void	ft_pcolor(char *msg, char *after, char *color)
{
	ft_putstr(color);
	if (after)
	{
		ft_putstr(msg);
		ft_putchar(' ');
		ft_putendl(after);
	}
	else
		ft_putendl(msg);
	ft_putstr(DEFAULT);
}
