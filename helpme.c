/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:28:36 by amusel            #+#    #+#             */
/*   Updated: 2017/03/31 16:28:42 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemmi.h"

void	antadd(struct s_lists *temp, int k, char c)
{
	int	i;

	i = (int)ft_strlen(temp->ways) + 1;
	while (--i >= k)
		temp->ways[i + 1] = temp->ways[i];
	temp->ways[k] = c;
	temp->ways[(int)ft_strlen(temp->ways) + 1] = '\0';
}

int		countspec(char *str)
{
	int	i;

	i = (int)ft_strlen(str);
	while (str[--i] == '-')
		str[i] = ' ';
	return (count(str));
}

void	validhelp(struct s_lists *temp, char *str, char *f)
{
	temp->end = str;
	temp->r = ft_strjoin(temp->r, temp->end);
	temp->r = ft_strjoin_free(&temp->r, &f);
}

int		count(char *str)
{
	int i;
	int ret;

	if (str[0] == '\0')
		return (10000);
	i = -1;
	ret = 0;
	while (str[++i])
		if (str[i] == '-')
			ret++;
	return (ret);
}

int		cmp(struct s_lists *temp, char *tep)
{
	char	*str;
	int		i;
	int		j;

	temp->ret++;
	j = -1;
	i = (int)ft_strlen(temp->ways) - 1;
	str = ft_strnew(100);
	while (temp->ways[i] != '|' && i > -1)
		i--;
	while (temp->ways[++i] != '|' && temp->ways[i])
		str[++j] = temp->ways[i];
	str[++j] = '\0';
	if (ft_strstr(str, tep) != 0)
	{
		while (temp->ways[--i] != '|' && i > -1)
			temp->ways[i] = '\0';
		return (0);
	}
	return (1);
}
