/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:22:55 by gperroch          #+#    #+#             */
/*   Updated: 2016/05/19 09:56:59 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_record(t_core *c, int argc, char **argv, int i)
{
	c->options |= (!ft_strcmp(argv[i], "-dump")) ? OPT_DUMP : 0;
	c->options |= (!ft_strcmp(argv[i], "-s")) ? OPT_S : 0;
	c->options |= (!ft_strcmp(argv[i], "-v")) ? OPT_V : 0;
	c->options |= (!ft_strcmp(argv[i], "-n")) ? OPT_N : 0;
	c->options |= (!ft_strcmp(argv[i], "-c")) ? OPT_C : 0;
	if (i < argc - 1 && !ft_strcmp(argv[i], "-dump"))
		c->dumps = ft_atoi(argv[i + 1]);
	if (i < argc - 1 && !ft_strcmp(argv[i], "-s"))
		c->sdumps = ft_atoi(argv[i + 1]);
	if (i < argc - 1 && !ft_strcmp(argv[i], "-v"))
	{
		c->verbose_level |= (ft_strchr(argv[i + 1], '1')) ? 1023 : 0;
		c->verbose_level |= (ft_strchr(argv[i + 1], '2')) ? 2 : 0;
		c->verbose_level |= (ft_strchr(argv[i + 1], '3')) ? 4 : 0;
		c->verbose_level |= (ft_strchr(argv[i + 1], '4')) ? 8 : 0;
		c->verbose_level |= (ft_strchr(argv[i + 1], '5')) ? 16 : 0;
		c->verbose_level |= (ft_strchr(argv[i + 1], '6')) ? 32 : 0;
		c->verbose_level |= (ft_strchr(argv[i + 1], '7')) ? 64 : 0;
		c->verbose_level |= (ft_strchr(argv[i + 1], '8')) ? 128 : 0;
		c->verbose_level |= (ft_strchr(argv[i + 1], '9')) ? 256 : 0;
	}
}

static void	ft_opt_error(int argc, char **argv, int i)
{
	if ((!ft_strcmp(argv[i], "-s") || !ft_strcmp(argv[i], "-n")
				|| !ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-v"))
			&& (i == argc - 1 || !ft_isnumber(argv[i + 1])))
		usage();
	if (!ft_strcmp(argv[i], "-n") && (i >= argc - 2 ||
				argv[i + 2][0] == '-' || ft_isnumber(argv[i + 2])))
		usage();
	if ((ft_strcmp(argv[i], "-s") && ft_strcmp(argv[i], "-n")
				&& ft_strcmp(argv[i], "-dump") && ft_strcmp(argv[i], "-v")
				&& ft_strcmp(argv[i], "-c"))
			&& (argv[i][0] == '-'))
		usage();
}

static void	ft_next_number(int *number, int *champ_numbers, int nb_champ)
{
	int		verif;
	int		i;

	verif = 1;
	while (verif)
	{
		verif = 0;
		i = -1;
		while (++i < nb_champ)
			if (champ_numbers[i] == *number)
			{
				(*number)++;
				verif = 1;
			}
	}
}

static void	ft_number_champion(int argc, char **argv, int *champ_numbers,
		int nb_champ)
{
	int		number;
	int		i;
	int		j;

	number = 1;
	i = 0;
	j = -1;
	while (++i < argc)
	{
		if (argv[i][0] != '-' && !ft_isnumber(argv[i]))
		{
			while (++j < nb_champ)
			{
				if (champ_numbers[j] == 0)
				{
					ft_next_number(&number, champ_numbers, nb_champ);
					champ_numbers[j] = number;
				}
			}
		}
	}
}

void		parse_options(t_core *c, int argc, char **argv)
{
	int		i;

	i = -1;
	while (++i < argc)
	{
		ft_opt_error(argc, argv, i);
		ft_record(c, argc, argv, i);
		if (i > 0 && argv[i][0] != '-' && !ft_isnumber(argv[i]))
		{
			ft_tabjoin_str(&c->warriors_path, c->nb_warriors, argv[i]);
			if (i >= 3 && !ft_strcmp(argv[i - 2], "-n")
					&& ft_isnumber(argv[i - 1]))
				ft_tabjoin_int(&c->warriors_numbers, c->nb_warriors,
								ft_atoi(argv[i - 1]));
			else
				ft_tabjoin_int(&c->warriors_numbers, c->nb_warriors, 0);
			c->nb_warriors++;
		}
	}
	ft_number_champion(argc, argv, c->warriors_numbers, c->nb_warriors);
	ft_double_number(c->warriors_numbers, c->nb_warriors);
}
