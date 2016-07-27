/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:33:37 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/06 12:00:13 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*lastchr;

	lastchr = 0;
	while (*s)
	{
		if (c == *s)
			lastchr = s;
		s++;
	}
	if (c == *s)
		return (char *)(s);
	return (char *)(lastchr);
}
