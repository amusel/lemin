/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:11:22 by amusel            #+#    #+#             */
/*   Updated: 2017/02/03 20:11:24 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lsc2(struct s_lis *temp, int k, int i, int width)
{
	int	count;

	count = 0;
	if (k == temp->lscpoint && i != 1000)
	{
		while (width-- > 0 && ft_memchr(temp->mod, '-', 5) == 0 && \
				ft_memchr(temp->mod, '0', 5))
			write(1, "0", 1);
		width++;
		while (width-- > 0 && ft_memchr(temp->mod, '-', 5) == 0)
			write(1, " ", 1);
		while ((temp->lsc[i] && (count < temp->lscprec || \
				temp->lscprec == -1)) || \
				((temp->flag == 'c' || temp->flag == 'C') && count == 0))
			if ((int)ft_putchar_fd(temp->lsc[i++], 101) <= temp->lscprec - \
				count || temp->lscprec == -1 || temp->flag == 'C')
			{
				i--;
				count += (int)ft_putchar_fd(temp->lsc[i++], 1);
			}
		width++;
		while (width-- > 0 && ft_memchr(temp->mod, '-', 5))
			write(1, " ", 1);
	}
	return (count);
}

char	*solvenorm(struct s_lis *temp, char *ret, char *str)
{
	if (ft_memchr(temp->mod, '-', 5) > 0 || (temp->flag == 'p' && \
		ft_memchr(temp->mod, '0', 5)))
		ret = ft_strjoin(str, ret);
	else
		ret = ft_strjoin(ret, str);
	return (ret);
}

char	*flagsnorm(struct s_lis *temp, char *str)
{
	if (ft_memchr(temp->mod, '0', 5) && \
	ft_memchr(temp->mod, '-', 5) == 0 && (temp->prec == -1 || \
	(temp->flag == 'c' || temp->specflag[0] > 0 || str[0] == '\0')))
		return ("s");
	else
		return (NULL);
}

void	clr(struct s_lis *temp)
{
	temp = NULL;
	free(temp);
}

char	*fucking(char *ret, char *buf)
{
	char	*t;
	int		i;
	int		j;

	i = -1;
	j = -1;
	t = ret;
	ret = NULL;
	free(ret);
	ret = (char *)malloc(sizeof(ret) * (ft_strlen(t) + ft_strlen(buf) + 10));
	while (t[++i])
		ret[i] = t[i];
	while (buf[++j])
		ret[i++] = buf[j];
	ret[i] = '\0';
	return (ret);
}
