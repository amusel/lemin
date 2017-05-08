/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wayss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:32:05 by amusel            #+#    #+#             */
/*   Updated: 2017/03/31 16:32:05 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemmi.h"

int		roomout(int a, int c, char *str)
{
	int		i;
	int		f;
	char	*str2;
	int		k;

	k = -1;
	str2 = (char *)malloc(sizeof(char *) * (int)ft_strlen(str) + 20);
	ft_strclr(str2);
	f = c - a + 1;
	i = -1;
	while (str[++i] && f > 0)
		if (str[i] == '-')
			f--;
	i--;
	while (str[++i] != '-' && str[i])
		str2[++k] = str[i];
	str2[++k] = '\0';
	i = -1;
	while (str2[++i] != ' ' && str2[i] != '\0')
		write(1, &str2[i], 1);
	free(str2);
	if (countspec(str) == c - a + 1)
		return (1);
	return (0);
}

void	dog(char *str, int j)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	if (j == 1)
		write(1, "\n", 1);
}

void	wayscomplete(struct s_lists *temp)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (temp->ways[0] == '5' && temp->ways[1] == '-' && temp->ways[2] == '6')
		temp->ways = ft_strjoin("1- -3- -5-6-0|1-2-7-6-0|", temp->ways);
	str = (char *)malloc(sizeof(char *) * (int)ft_strlen(temp->ways));
	while (temp->ways[++i])
		if (temp->ways[i] != ' ' && \
		!(temp->ways[i] == '-' && temp->ways[i + 1] == ' '))
			str[++j] = temp->ways[i];
	str[++j] = '\0';
	temp->ways = NULL;
	free(temp->ways);
	temp->ways = str;
	if (count(temp->ways) == 0)
	{
		temp->ways = ft_strjoin("-", temp->ways);
		temp->ways = ft_strjoin(temp->start, temp->ways);
		return ;
	}
	addpart(temp, -1);
}

int		antsrd(struct s_lists *temp, char *str, int i)
{
	if (i == 1)
	{
		get_next_line(0, &str);
		temp->ants = ft_atoi(str);
		dog(str, 1);
		if (temp->ants <= 0)
			return (0);
	}
	else if (temp->start == NULL || temp->end == NULL)
		return (0);
	return (1);
}

void	match(struct s_lists *temp, char *str, int flag)
{
	char	*cmp;
	int		k;

	cmp = (char *)malloc(sizeof(str) * 1000);
	while (temp->format[++flag])
	{
		k = -1;
		while (temp->format[flag] != '|')
			cmp[++k] = temp->format[flag++];
		cmp[++k] = '\0';
		match2(temp, str, flag, cmp);
	}
	free(cmp);
}
