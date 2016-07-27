/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:30:17 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/01/24 11:32:45 by tpaulmye         ###   ########.fr       */
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

long long	ft_atoll(const char *str)
{
	long long	posneg;
	long long	num;

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
		num = (num * 10) + ((long long)*str - 48);
		str++;
	}
	return (num * posneg);
}
