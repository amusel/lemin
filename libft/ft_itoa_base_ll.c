/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:16:45 by amusel            #+#    #+#             */
/*   Updated: 2017/01/26 19:16:47 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define RET(num) ((num < 0) ? (-num) : (num))

void	fuz(long long int base, long long int value, char *str, int *i)
{
	char	*b;

	b = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		fuz(base, value / base, str, i);
	str[(*i)++] = b[RET(value % base)];
}

char	*ft_itoa_base_ll(long long int value, long long int base)
{
	static char	str[40];
	int			i;

	i = 0;
	ft_strclr(str);
	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && value < 0)
		str[i++] = '-';
	fuz(base, value, str, &i);
	str[i] = '\0';
	return (str);
}
