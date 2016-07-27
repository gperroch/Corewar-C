/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:45:21 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/03 20:01:51 by tpaulmye         ###   ########.fr       */
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

int			ft_atoi(const char *str)
{
	int			posneg;
	int			num;

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
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (num * posneg);
}
