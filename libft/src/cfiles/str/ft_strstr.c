/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:39:59 by tpaulmye          #+#    #+#             */
/*   Updated: 2014/11/03 17:20:01 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char *)s1);
	if (!*s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			while (s2[j] == s1[i + j])
			{
				j++;
				if (!s2[j])
					return ((char *)(s1 + i));
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
