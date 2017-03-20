/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:06:42 by amusel            #+#    #+#             */
/*   Updated: 2016/12/06 16:27:12 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
#define BIT7 127
#define BIT11 2047
#define BIT16 65535
#define BIT21 2097151
#define BIT26 67108863
#define BIT31 2147483647

static void		ft_putchar_fd_2(const uint32_t symbol, char *rt)
{
	if (symbol <= BIT21)
	{
		rt[0] = ((symbol & 1835008) >> 18) | 240;
		rt[1] = ((symbol & 258048) >> 12) | 128;
		rt[2] = ((symbol & 4032) >> 6) | 128;
		rt[3] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT26)
	{
		rt[0] = ((symbol & 50331648) >> 24) | 248;
		rt[1] = ((symbol & 16515072) >> 18) | 128;
		rt[2] = ((symbol & 258048) >> 12) | 128;
		rt[3] = ((symbol & 4032) >> 6) | 128;
		rt[4] = (symbol & 63) | 128;
	}
	else
	{
		rt[0] = ((symbol & 1073741824) >> 30) | 252;
		rt[1] = ((symbol & 1056964608) >> 24) | 128;
		rt[2] = ((symbol & 16515072) >> 18) | 128;
		rt[3] = ((symbol & 258048) >> 12) | 128;
		rt[4] = ((symbol & 4032) >> 6) | 128;
		rt[5] = (symbol & 63) | 128;
	}
}

char			*fun(char *rt, const uint32_t symbol)
{
	rt[0] = ((symbol & 61440) >> 12) | 224;
	rt[1] = ((symbol & 4032) >> 6) | 128;
	rt[2] = (symbol & 63) | 128;
	return (rt);
}

size_t			ft_putchar_fd(const uint32_t symbol, const int fd)
{
	char	*rt;
	size_t	ct;

	ct = 1;
	rt = ft_strnew(6);
	if (symbol <= BIT7)
		rt[0] = symbol;
	else if (symbol <= BIT11)
	{
		ct = 2;
		rt[0] = ((symbol & 1984) >> 6) | 192;
		rt[1] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT16)
	{
		rt = fun(rt, symbol);
		ct = 3;
	}
	else
		ft_putchar_fd_2(symbol, rt);
	if (fd < 100)
		ct = write(fd, rt, sizeof(char)) + write(fd, &rt[1], ft_strlen(&rt[1]));
	ft_strdel(&rt);
	return (ct);
}
