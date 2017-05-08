/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 14:55:16 by amusel            #+#    #+#             */
/*   Updated: 2017/01/29 14:55:18 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clcsls(va_list ap, struct s_lis *temp, wchar_t *tmp)
{
	int i;

	i = -1;
	if (temp->flag == 'S' || temp->flag == 's')
		temp->lsc = (wchar_t *)va_arg(ap, int *);
	if (temp->flag == 'C' || temp->flag == 'c')
	{
		tmp[0] = (wchar_t)va_arg(ap, int);
		tmp[1] = '\0';
	}
	if (temp->flag != 'C')
		while (++i < temp->prec)
			tmp[i] = temp->lsc[i];
	if (i > 0 || temp->flag == 'c' || temp->flag == 'C')
		temp->lsc = tmp;
	temp->lscpoint = temp->j;
	temp->lscwidth = temp->width;
	temp->lscprec = temp->prec;
}

int		specflag(const char *p, int *i, struct s_lis *temp, va_list ap)
{
	if (p[*i] == '*' && p[(*i) - 1] == '.')
	{
		temp->prec = va_arg(ap, int);
		if (temp->prec < 0)
			temp->prec = -1;
		return (0);
	}
	else if (p[*i] == '*')
	{
		temp->width = va_arg(ap, int);
		if (temp->width == 0)
			temp->width = -1;
		else if (temp->width < 0)
		{
			temp->width = -temp->width;
			temp->mod[ft_strlen(temp->mod)] = '-';
		}
		return (0);
	}
	temp->specflag[0] = p[(*i)];
	temp->specflag[1] = '\0';
	if (temp->specflag[0] != '\0')
		return (((*i)++) - (*i) + 1);
	else
		return (((*i)--) - (*i) + 1);
}

int		widthmanagelsc(struct s_lis *temp)
{
	int i;
	int	width;
	int j;

	j = 0;
	i = 0;
	while (temp->lsc[j] && (temp->lscprec == -1 || \
		(int)ft_putchar_fd(temp->lsc[j++], 101) <= temp->lscprec - i))
		i += (int)ft_putchar_fd((const u_int32_t)temp->lsc[j++], 101);
	if (i > temp->lscprec && temp->lscprec != -1)
		i = temp->lscprec;
	width = temp->lscwidth - i;
	if (width < 0)
		width = 0;
	return (width);
}

int		lsc(struct s_lis *temp, char *ret)
{
	int k;
	int width;
	int count;

	width = 0;
	count = 0;
	k = 0;
	if (temp->lsc == NULL)
	{
		ft_putstr(ret);
		k = (int)ft_strlen(ret);
		ft_putstr("(null)");
		count += 6;
	}
	else
		width = widthmanagelsc(temp);
	while (k <= temp->j)
	{
		if (count != 6)
			count = lsc2(temp, k, 0, width);
		if (ret[k] > 0)
			ft_putchar(ret[k]);
		k++;
	}
	return (width + count + (int)ft_strlen(ret));
}

int		help(struct s_lis *temp, char *ret)
{
	int i;

	i = -1;
	if (temp->flag == 'S' || (temp->flag == 's' && temp->type[0] == 'l'))
		return (lsc(temp, ret));
	else if (ft_memchr(temp->mod, '-', 5) == 0 && \
			(temp->prec == -1 || temp->flag == 'c') && temp->width > -1)
		temp->c = temp->c + temp->width - 1;
	if ((int)ft_strlen(ret) == '\0' && temp->flag == '\0')
		return (temp->ret);
	if (temp->cflag > 0)
	{
		while (temp->j >= ++i)
		{
			if (temp->c == i)
				ft_putchar('\0');
			if (ret[i])
				ft_putchar(ret[i]);
		}
		return ((int)ft_strlen(ret) + 1 + temp->ret);
	}
	ft_putstr(ret);
	return ((int)ft_strlen(ret) + temp->ret);
}
