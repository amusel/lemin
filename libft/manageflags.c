/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:35:07 by amusel            #+#    #+#             */
/*   Updated: 2017/01/27 19:35:08 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manageoflags(va_list ap, struct s_lis *temp)
{
	char	*ret;

	ret = NULL;
	if (temp->flag == 'O')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned long long int), 8);
	else if (temp->type[0] == 'h' && temp->type[1] == 'h')
		ret = ft_itoa_base_unsig((unsigned char)va_arg(ap, int), 8);
	else if (temp->type[0] == 'l' && temp->type[1] == 'l')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned long long int), 8);
	else if (temp->type[0] == 'l')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned long int), 8);
	else if (temp->type[0] == 'h')
		ret = ft_itoa_base_unsig((unsigned short)va_arg(ap, int), 8);
	else if (temp->type[0] == 'j')
		ret = ft_itoa_base_unsig(va_arg(ap, uintmax_t), 8);
	else if (temp->type[0] == 'z')
		ret = ft_itoa_base_unsig(va_arg(ap, size_t), 8);
	else if (temp->type[0] == '\0')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned int), 8);
	return (ret);
}

char	*managexflags(va_list ap, struct s_lis *temp)
{
	char	*ret;

	ret = NULL;
	if (temp->type[0] == 'h' && temp->type[1] == 'h')
		ret = ft_itoa_base_unsig((unsigned char)va_arg(ap, int), 16);
	else if (temp->type[0] == 'l' && temp->type[1] == 'l')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned long long int), 16);
	else if (temp->type[0] == 'l')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned long int), 16);
	else if (temp->type[0] == 'h')
		ret = ft_itoa_base_ll(va_arg(ap, int), 16);
	else if (temp->type[0] == 'j')
		ret = ft_itoa_base_unsig(va_arg(ap, uintmax_t), 16);
	else if (temp->type[0] == 'z')
		ret = ft_itoa_base_unsig(va_arg(ap, size_t), 16);
	else if (temp->type[0] == '\0')
		ret = ft_itoa_base_unsig(va_arg(ap, unsigned int), 16);
	return (ret);
}

char	*managesflags(va_list ap, struct s_lis *temp)
{
	char	*ret;
	char	*retchar;

	retchar = ft_strnew(2);
	retchar[0] = '\0';
	retchar[1] = '\0';
	ret = NULL;
	if (temp->type[0] == 0 && temp->flag == 's')
		ret = va_arg(ap, char *);
	else if ((temp->flag == 99 || temp->flag == 67))
	{
		retchar[0] = va_arg(ap, int);
		ret = retchar;
		retchar = NULL;
		free(retchar);
		return (ret);
	}
	if (ret == NULL)
		ret = "(null)";
	return (ret);
}

int		c(struct s_lis *temp, char *str, int flag)
{
	temp->cflag++;
	str = ft_strjoin(str, (const char *)"");
	flag = 1;
	str[0] = ' ';
	temp->c = temp->j;
	return (flag);
}

char	*sc(va_list ap, struct s_lis *temp)
{
	char	*str;
	char	*ret;
	int		flag;

	flag = 0;
	if (temp->specflag[0] == '\0')
		str = managesflags(ap, temp);
	else
		str = temp->specflag;
	if (str[0] == '\0' && temp->flag != 's' && temp->flag != 'S')
		flag = c(temp, str, flag);
	if (temp->prec > -1 && temp->specflag[0] == '\0')
	{
		str = ft_strjoin(str, (const char *)"");
		str[temp->prec] = '\0';
	}
	ret = width(temp, str);
	if (flag)
	{
		ret = ft_strjoin(ret, (const char *)"");
		ret[ft_strlen(ret) - 1] = '\0';
	}
	return (ret);
}
