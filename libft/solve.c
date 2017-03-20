/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 14:03:55 by amusel            #+#    #+#             */
/*   Updated: 2017/01/29 14:04:05 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*solveint(va_list ap, struct s_lis *temp, char *str, char *sign)
{
	char	*ret;

	ret = NULL;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		str[0] = '0';
		str[1] = '0';
		sign[0] = '0';
		sign[1] = 'x';
		sign[2] = '\0';
		ret = sign;
	}
	else if (temp->flag == 'i' || temp->flag == 'd' || \
		temp->flag == 'u' || temp->flag == 'U' || temp->flag == 'D')
		ret = idu(ap, temp);
	else if (temp->flag == 'o' || temp->flag == 'O' || \
		temp->flag == 'X' || temp->flag == 'x')
		ret = ox(ap, temp);
	return (ret);
}

char	*precision(struct s_lis *temp, char *str)
{
	char	*ret;
	int		i;
	char	*sign;

	sign = (char *)malloc(sizeof(sign) * 10);
	ft_strclr(sign);
	if (temp->prec > -1 && temp->prec >= (int)ft_strlen(str))
	{
		ret = ft_strnew(temp->prec - ft_strlen(str));
		if (str[0] == '-' || str[0] == '+')
		{
			sign[0] = str[0];
			str[0] = '0';
		}
		if (str[0] == '0' && (temp->flag == 'x' || temp->flag == 'X'))
			sign = solveint(NULL, temp, str, sign);
	}
	else
		return (str);
	i = temp->prec - (int)ft_strlen(str);
	while (i-- > 0)
		ret[i] = '0';
	ret = ft_strjoin(ret, str);
	ret = ft_strjoin(sign, ret);
	return (ret);
}

char	*width(struct s_lis *temp, char *str)
{
	char	*ret;
	int		i;

	if (str[0] == '-')
		temp->mod[ft_strlen(temp->mod)] = '+';
	if (temp->width > -1 && temp->width > (int)ft_strlen(str))
	{
		ret = ft_strnew(temp->width - ft_strlen(str));
		if (str[0] > 47 && str[0] < 58 && ft_memchr(temp->mod, ' ', 5) && \
		temp->flag != 'u' && temp->flag != 'U' && temp->prec < 0)
			i = temp->width - (int)ft_strlen(str) - 1;
		else
			i = temp->width - (int)ft_strlen(str);
		while (i-- > 0)
			if (manageintmod(str, &i, ret, temp))
				i = i + 1 - 1;
			else
				ret[i] = ' ';
	}
	else
		return (str);
	return (solvenorm(temp, ret, str));
}

char	*solvechar(va_list ap, struct s_lis *temp)
{
	char	*ret;
	int		i;

	i = -1;
	if (temp->flag != 'p')
		ret = sc(ap, temp);
	else
	{
		ret = ft_itoa_base_unsig((uint64_t)va_arg(ap, void *), 16);
		if (ret[0] == '0' && temp->prec > -1)
			ret[0] = '\0';
		ret = precision(temp, ret);
		ret = ft_strjoin("0x", ret);
		ret = width(temp, ret);
		while (ret[++i])
			ret[i] = (char)ft_tolower(ret[i]);
	}
	return (ret);
}

char	*solve(va_list ap, struct s_lis *temp, char *ret)
{
	char	*buf;
	wchar_t *tmp;

	tmp = (wchar_t *)malloc(sizeof(tmp) * 100);
	if (temp->flag == 'S' || (temp->flag == 's' && temp->type[0] == 'l'))
	{
		clcsls(ap, temp, tmp);
		temp->ret += help(temp, ret);
		ft_strclr(ret);
		temp->flag = '\0';
		temp->j = 0;
		return (ret);
	}
	else if (ft_memchr("dDiuUoOxX", temp->flag, 9) > 0)
		buf = solveint(ap, temp, "", "");
	else
		buf = solvechar(ap, temp);
	ret = fucking(ret, buf);
	temp->j = (int)ft_strlen(ret);
	return (ret);
}
