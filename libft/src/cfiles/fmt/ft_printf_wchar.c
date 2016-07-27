/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 17:34:08 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/07 13:37:37 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Mask unicode :
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
** To print the returned char* from get_wc, just do a ft_putstr on it.
*/

#include "str.h"
#include "fmt.h"
#include "io.h"

static int		get_weight(unsigned int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n >> 1;
		size++;
	}
	return (size);
}

static char		fill_ret(unsigned char wc, int decal, int mask)
{
	char	ret;

	ret = 0;
	ret = wc;
	ret = (unsigned char)(ret << decal) >> decal;
	ret = ret | mask;
	return (ret);
}

static void		get_wc3(char *ret, wchar_t wc, t_arg *opt)
{
	ret[2] = fill_ret((unsigned char)wc, 2, 128);
	wc = wc >> 6;
	ret[1] = fill_ret((unsigned char)wc, 2, 128);
	wc = wc >> 6;
	ret[0] = fill_ret((unsigned char)wc, 4, 224);
	opt->sizearg = 3;
}

static void		get_wc4(char *ret, wchar_t wc, t_arg *opt)
{
	ret[3] = fill_ret((unsigned char)wc, 2, 128);
	wc = wc >> 6;
	ret[2] = fill_ret((unsigned char)wc, 2, 128);
	wc = wc >> 6;
	ret[1] = fill_ret((unsigned char)wc, 2, 128);
	wc = wc >> 6;
	ret[0] = fill_ret((unsigned char)wc, 5, 240);
	opt->sizearg = 4;
}

char			*get_wc(wchar_t wc, t_arg *opt)
{
	char			*ret;
	int				bits;

	bits = get_weight((unsigned int)wc);
	if ((ret = ft_strnew(4)) == NULL)
		ft_failure(NULL, "Malloc failed");
	if (bits <= 7)
	{
		ret[0] = (unsigned char)wc;
		opt->sizearg = 1;
	}
	else if (bits <= 11)
	{
		ret[1] = fill_ret((unsigned char)wc, 2, 128);
		wc = wc >> 6;
		ret[0] = fill_ret((unsigned char)wc, 3, 192);
		opt->sizearg = 2;
	}
	else if (bits > 11 && bits <= 16)
		get_wc3(ret, wc, opt);
	else
		get_wc4(ret, wc, opt);
	return (ret);
}
