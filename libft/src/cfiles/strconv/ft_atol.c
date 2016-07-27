/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:34:39 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/01/24 11:36:09 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_dig(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_space(int c)
{
	if (c == ' ' || c == '\n' || c == '\f' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

long		ft_atol(const char *str)
{
	long	posneg;
	long	num;

	num = 0;
	posneg = 1;
	while ((!ft_dig(*str)) && *str != '-' && *str != '+')
	{
		if ((!ft_dig(*str)) && (!ft_space(*str)) && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	if (*str == '-')
	{
		posneg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_dig(*str))
	{
		num = (num * 10) + ((long)*str - 48);
		str++;
	}
	return (num * posneg);
}
