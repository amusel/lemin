/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:41:01 by amusel            #+#    #+#             */
/*   Updated: 2017/01/26 15:41:03 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manageunflags(va_list ap, struct s_lis *temp)
{
	char	*ret;

	ret = NULL;
	if (temp->flag == 'U')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned long long int), 10);
	else if (temp->type[0] == 'h' && temp->type[1] == 'h')
		ret = ft_itoa_base_unsig((unsigned char)va_arg(ap, int), 10);
	else if (temp->type[0] == 'l' && temp->type[1] == 'l')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned long long int), 10);
	else if (temp->type[0] == 'l')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned long int), 10);
	else if (temp->type[0] == 'h')
		ret = ft_itoa_base_unsig((unsigned short)va_arg(ap, int), 10);
	else if (temp->type[0] == 'j')
		ret = ft_itoa_base_unsig(va_arg(ap, uintmax_t), 10);
	else if (temp->type[0] == 'z')
		ret = ft_itoa_base_unsig(va_arg(ap, size_t), 10);
	else if (temp->type[0] == '\0')
		ret = ft_itoa_base_ll(va_arg(ap, unsigned int), 10);
	return (ret);
}

char	*manageintflags(va_list ap, struct s_lis *temp)
{
	char	*ret;

	if (temp->type[0] == 'h' && temp->type[1] == 'h' && temp->flag != 'D')
		ret = ft_itoa_base_ll((signed char)va_arg(ap, int), 10);
	else if (temp->type[0] == 'l' && temp->type[1] == 'l')
		ret = ft_itoa_base_ll(va_arg(ap, long long int), 10);
	else if (temp->type[0] == 'l')
		ret = ft_itoa_base_ll(va_arg(ap, long int), 10);
	else if (temp->type[0] == 'h' && temp->flag != 'D')
		ret = ft_itoa_base_ll((short int)va_arg(ap, int), 10);
	else if (temp->type[0] == 'j')
		ret = ft_itoa_base_ll(va_arg(ap, intmax_t), 10);
	else if (temp->type[0] == 'z')
		ret = ft_itoa_base_ll(va_arg(ap, size_t), 10);
	else if (temp->type[0] == '\0' && temp->flag != 'D')
		ret = ft_itoa_base_ll(va_arg(ap, int), 10);
	else
		ret = ft_itoa_base_ll(va_arg(ap, long long int), 10);
	return (ret);
}

char	*idu(va_list ap, struct s_lis *temp)
{
	char	*str;
	char	*ret;
	char	*sign;

	sign = "+";
	if (temp->flag == 'u' || temp->flag == 'U')
		str = manageunflags(ap, temp);
	else
		str = manageintflags(ap, temp);
	if (ft_memchr(temp->mod, '+', 5) && str[0] != '-' && \
		temp->flag != 'u' && temp->flag != 'U')
		str = ft_strjoin(sign, str);
	if (temp->prec == 0 && str[0] == '0')
		str[0] = '\0';
	if (str[0] == '+' && str[1] == '0' && temp->prec == 0)
		str[1] = '\0';
	str = precision(temp, str);
	ret = width(temp, str);
	if (ret[0] != '-' && ret[0] != '+' && \
	ft_memchr(temp->mod, 32, 5) && temp->flag != 'u' && temp->flag != 'U')
		ret = ft_strjoin(" ", ret);
	return (ret);
}

int		manageintmod(char *str, int *i, char *ret, struct s_lis *temp)
{
	static char	sign = '0';
	static char oxsign = '0';

	if ((sign == '+' || sign == '-') && ft_memchr(temp->mod, '+', 5) == 0)
		sign = '0';
	if (flagsnorm(temp, str) != NULL)
	{
		if (str[0] == '-' || str[0] == '+')
		{
			sign = str[0];
			str[0] = '0';
		}
		if (ft_memchr("oOxX", temp->flag, 4) && \
				ft_memchr(temp->mod, '#', 5) && str[1] != '0')
		{
			oxsign = str[1];
			str[1] = '0';
		}
		ret[(*i)] = '0';
		ret[0] = sign;
		if (ft_memchr("oOxX", temp->flag, 4))
			ret[1] = oxsign;
		return (1);
	}
	return (0);
}

char	*ox(va_list ap, struct s_lis *temp)
{
	char	*str;
	char	*ret;
	int		i;

	i = -1;
	if (temp->flag == 'o' || temp->flag == 'O')
		str = manageoflags(ap, temp);
	else
		str = managexflags(ap, temp);
	if (temp->flag == 'x')
		while (str[++i])
			str[i] = (char)ft_tolower(str[i]);
	if (temp->prec == 0 && str[0] == '0')
		str[0] = '\0';
	if (ft_memchr(temp->mod, '#', 5) && (temp->flag == 'o' || \
		temp->flag == 'O') && str[0] != '0')
		str = ft_strjoin("0", str);
	else if (ft_memchr(temp->mod, '#', 5) && str[0] != '0' && str[0] != 0)
		str = ft_strjoin("0x", str);
	if (temp->flag == 'X')
		while (str[++i])
			str[i] = (char)ft_toupper(str[i]);
	str = precision(temp, str);
	ret = width(temp, str);
	return (ret);
}
