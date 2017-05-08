/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsig.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:16:45 by amusel            #+#    #+#             */
/*   Updated: 2017/01/28 18:06:34 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define RET(num) ((num < 0) ? (-num) : (num))

void	my(unsigned long long int value, int base, char *str, int *i)
{
	char	*b;

	b = "0123456789ABCDEF";
	if (value >= (unsigned long long)base)
		my(value / base, base, str, i);
	str[(*i)++] = b[RET(value % base)];
}

char	*ft_itoa_base_unsig(unsigned long long int value, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(str) * 40);
	ft_strclr(str);
	if (base < 2 || base > 16)
		return (NULL);
	my(value, base, str, &i);
	str[i] = '\0';
	if (ft_memchr("0123456789ABCDEF", str[i - 1], 16) == 0)
		str[i - 1] = '8';
	return (str);
}
