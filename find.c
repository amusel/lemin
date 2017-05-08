/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:57:37 by amusel            #+#    #+#             */
/*   Updated: 2017/03/31 15:57:38 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemmi.h"

char	*addpart3(struct s_lists *temp, int *i, char *ret, int *k)
{
	(*i)--;
	while (temp->ways[++(*i)] != '|' && temp->ways[*i])
		ret[++(*k)] = temp->ways[*i];
	(*i)--;
	while (temp->ways[*i] != '|')
		(*i)--;
	ret[++(*k)] = '\0';
	return (ret);
}

char	*addpart2(struct s_lists *temp, char *ret, char *str, char *fin)
{
	int	j;
	int i;
	int c;
	int k;

	c = -1;
	i = -1;
	while (temp->ways[++i])
	{
		j = -1;
		while (temp->ways[i] != '|')
			i++;
		while (fin[++c] != '|')
			str[++j] = fin[c];
		str[++j] = '\0';
		i++;
		j = -1;
		k = -1;
		while (str[++j] != temp->ways[i] && temp->ways[i])
			ret[++k] = str[j];
		ret = addpart3(temp, &i, ret, &k);
		fin = ft_strjoin(fin, ret);
		fin = ft_strjoin(fin, "|");
	}
	return (fin);
}

void	addpart(struct s_lists *temp, int i)
{
	char	*str;
	char	*ret;
	char	*fin;

	ret = (char *)malloc(sizeof(char *) * (int)ft_strlen(temp->ways));
	str = (char *)malloc(sizeof(char *) * (int)ft_strlen(temp->ways));
	fin = (char *)malloc(sizeof(char *) * (int)ft_strlen(temp->ways));
	while (temp->ways[++i] != '|' && temp->ways[i])
		fin[i] = temp->ways[i];
	fin[i] = '|';
	fin[++i] = '\0';
	fin = addpart2(temp, ret, str, fin);
	fin[ft_strlen(fin) - 1] = '\0';
	temp->ways = fin;
	search(temp);
	manageways(temp);
	free(ret);
	free(str);
	free(fin);
}

void	pasta2(struct s_lists *temp, int *c, char *str, int *a)
{
	int i;
	int k;

	k = -1;
	while (temp->ways[++k] != '\0')
	{
		i = -1;
		while (temp->ways[k] != '|' && temp->ways[k])
			str[++i] = temp->ways[k++];
		str[++i] = '\0';
		if (++temp->c / 2 <= temp->ants && str[i - *a] == '-' && \
						(str[i - *a + 1] == '-' || str[i - *a + 1] == '\0'))
			if (temp->c++ && countspec(str) + *a > *c)
			{
				write(1, "L", 1);
				ft_putstr(ft_itoa_base_ll(temp->c / 2, 10));
				write(1, "-", 1);
				i = roomout(*a, *c, str);
				write(1, " ", 1);
			}
		if (temp->c / 2 >= temp->ants && i == 1)
			*c = -1;
	}
}

void	pasta(struct s_lists *temp)
{
	int		c;
	char	*str;
	int		a;

	c = 0;
	str = (char *)malloc(sizeof(char *) * (int)ft_strlen(temp->ways) + 10);
	while (++c)
	{
		a = 0;
		temp->c = 0;
		while (++a <= c)
		{
			str = (char *)malloc((int)ft_strlen(temp->ways) + 10);
			ft_strclr(str);
			pasta2(temp, &c, str, &a);
		}
		free(str);
		if (temp->c / 2 <= temp->ants + 20)
			write(1, "\n", 1);
		if (c == -1)
			break ;
	}
}
