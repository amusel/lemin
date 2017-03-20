/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:12:49 by amusel            #+#    #+#             */
/*   Updated: 2017/02/04 14:12:56 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsenumb(va_list ap, const char *p, int *i, struct s_lis *temp)
{
	char	*str;
	int		k;

	k = 0;
	if (p[*i] == 46)
		(*i)++;
	str = ft_strnew(ft_strlen(p) - (*i));
	if (p[*i] == '*')
	{
		specflag(p, i, temp, ap);
		return ;
	}
	while (p[(*i)] > 47 && p[(*i)] < 58)
	{
		str[k++] = p[(*i)];
		(*i)++;
	}
	(*i)--;
	str[k] = '\0';
	if ((p[(*i) - ft_strlen(str)]) == 46)
		temp->prec = ft_atoi(str);
	else
		temp->width = ft_atoi(str);
	free(str);
}

int		parse2(va_list ap, const char *p, int *i, struct s_lis *temp)
{
	int k;

	k = 0;
	if ((p[(*i)] == 'h' && p[(*i) + 1] == 'h') || \
		(p[(*i)] == 'l' && p[(*i) + 1] == 'l'))
	{
		temp->type[k++] = p[*i];
		temp->type[k] = p[(*i)++];
	}
	else if (p[*i] == 'h' || p[*i] == 'l' || p[*i] == 'z' || p[*i] == 'j')
	{
		if (temp->type[k] == 'h' || !(temp->type[k]))
			temp->type[k] = p[*i];
	}
	else if ((p[*i] > 48 && p[*i] < 58) || p[*i] == 46 || p[*i] == '*')
		parsenumb(ap, p, i, temp);
	else
		return (1);
	return (0);
}

int		clrtemp(struct s_lis *temp, int k, char *ret)
{
	if (k == 1)
	{
		ft_strclr(temp->type);
		ft_strclr(temp->mod);
		ft_strclr(temp->str);
		temp->flag = '\0';
		temp->width = -1;
		temp->prec = -1;
		temp->cflag = 0;
		temp->c = 0;
		ft_strclr(temp->specflag);
		temp->lscwidth = 0;
		temp->lscprec = -1;
	}
	else
		return (help(temp, ret));
	return (-1);
}

int		parse(va_list ap, const char *p, int *i, struct s_lis *temp)
{
	int				k;
	char			*str;

	k = 0;
	str = "sSpdDioOuUxXcC";
	clrtemp(temp, 1, str);
	while (p[(*i)++] && !(temp->flag))
	{
		if (p[(*i)] == '%')
		{
			temp->specflag[0] = '%';
			return (((*i)++) - (*i) + 1);
		}
		else if (ft_memchr(str, p[(*i)], 14) > 0)
			temp->flag = p[(*i)];
		else if ((p[*i] == 35 || p[*i] == 45 || p[*i] == 43 || p[*i] == 48 || \
				p[(*i)] == ' '))
		{
			if (ft_memchr(temp->mod, p[(*i)], 5) == 0)
				temp->mod[k++] = p[*i];
		}
		else if (parse2(ap, p, i, temp))
			return (specflag(p, i, temp, NULL));
	}
	return (0);
}

int		ft_printf(const char *restrict str, ...)
{
	int				i;
	char			*ret;
	struct s_lis	*temp;
	va_list			ap;
	int				k;

	i = -1;
	temp = (struct s_lis *)malloc(sizeof(temp) * 33);
	temp->j = 0;
	ret = (ft_strnew(ft_strlen(str)));
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] != '%')
		{
			ret[temp->j++] = str[i];
			ret[temp->j] = '\0';
		}
		else if (parse(ap, str, &i, temp) == 0 && i-- > -1)
			ret = solve(ap, temp, ret);
	}
	va_end(ap);
	k = clrtemp(temp, 0, ret);
	clr(temp);
	return (k);
}
