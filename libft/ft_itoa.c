/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:48:57 by amusel            #+#    #+#             */
/*   Updated: 2016/12/07 15:33:42 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	int			is_neg;
	long long	ncpy;

	i = 0;
	is_neg = 0;
	ncpy = n;
	ncpy = ncpy < 0 ? -ncpy : ncpy;
	if (n < 0)
		is_neg = 1;
	str = (char *)malloc(sizeof(char *) * 100);
	ft_strclr(str);
	while (ncpy >= 10)
	{
		str[i++] = ncpy % 10 + '0';
		ncpy /= 10;
	}
	str[i] = ncpy % 10 + '0';
	if (is_neg == 1)
		str[++i] = '-';
	str[i + 1] = '\0';
	return (ft_strrev(str));
}
