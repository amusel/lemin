/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:34:53 by exam              #+#    #+#             */
/*   Updated: 2017/01/24 12:07:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define RET(num) ((num < 0) ? -num : num)

void	func(int base, int value, char *str, int *i)
{
	char	*b;

	b = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		func(base, value / base, str, i);
	str[(*i)++] = b[RET(value % base)];
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(str) * 100);
	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && value < 0)
		str[i++] = '-';
	if (value == -2147483648 && base == 10)
	{
		str = "-2147483648";
		return (str);
	}
	func(base, value, str, &i);
	str[i] = '\0';
	return (str);
}
