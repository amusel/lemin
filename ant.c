/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:36:33 by amusel            #+#    #+#             */
/*   Updated: 2017/03/31 18:37:24 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemmi.h"

int		input(struct s_lists *temp, int flag)
{
	char	*str;
	int		i;

	str = NULL;
	if (antsrd(temp, str, 1) == 0)
		return (0);
	while (get_next_line(0, &str))
	{
		dog(str, 1);
		i = 0;
		while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
			i++;
		str[i] = '\0';
		if (ft_strnstr(str, "##start", 7))
			flag = 1;
		else if (ft_strnstr(str, "##end", 5))
			flag = 2;
		else if (ft_strnstr(str, "#", 1))
			continue ;
		else if (ft_strnstr(str, "L", 1))
			return (0);
		else if (valid(temp, str, &flag) == 0)
			return (0);
	}
	return (1);
}

void	antsoutput2(struct s_lists *temp, char *str, int flag)
{
	char	*tmp;
	int		j;
	int		k;

	k = -1;
	tmp = (char *)malloc(sizeof(char *) * (int)ft_strlen(temp->ways) + 100);
	while (temp->ways[++k] != '\0')
	{
		j = -1;
		flag++;
		while (temp->ways[k] != '|' && temp->ways[k])
			str[++j] = temp->ways[k++];
		str[++j] = '\0';
		if (count(str) < count(tmp))
		{
			temp->ret = flag;
			j = -1;
			while (str[++j])
				tmp[j] = str[j];
		}
	}
	tmp = NULL;
	free(tmp);
}

void	antsoutput(struct s_lists *temp)
{
	int		i;
	int		k;
	char	*str;
	int		flag;

	str = (char *)malloc(sizeof(char *) * (int)ft_strlen(temp->ways) + 100);
	i = temp->ants + 1;
	while (--i > 0)
	{
		free(str);
		str = (char *)malloc(sizeof(char *) * (int)ft_strlen(temp->ways) + 100);
		k = -1;
		antsoutput2(temp, str, -1);
		flag = temp->ret;
		while (flag > -1)
			if (temp->ways[++k] == '|' && temp->ways[k])
				flag--;
		antadd(temp, k, '-');
	}
	free(str);
	pasta(temp);
}

void	search2(struct s_lists *temp, char *str, char *cut, int *flag)
{
	int	i;
	int k;

	i = -1;
	while (temp->ways[++i])
	{
		if (temp->ways[i] == ' ' && temp->ways[i + 1] == ' ')
			while (temp->ways[i] != '|')
				i++;
		k = -1;
		while (temp->ways[i] != '|')
			str[++k] = temp->ways[i++];
		str[++k] = '\0';
		if (ft_strstr(str, temp->end) == 0 && str[0] != '\0')
			while (temp->ways[--i] != '|' && temp->ways[i])
				temp->ways[i] = ' ';
		else if (count(str) < count(cut))
		{
			*flag = i;
			k = -1;
			while (str[++k])
				cut[k] = str[k];
			cut[k] = '\0';
		}
	}
}

void	search(struct s_lists *temp)
{
	char	*str;
	char	*cut;
	int		flag;

	flag = 0;
	cut = (char *)malloc(sizeof(str) * 1000);
	str = (char *)malloc(sizeof(str) * 1000);
	search2(temp, str, cut, &flag);
	temp->format = ft_strjoin(temp->format, cut);
	temp->format = ft_strjoin(temp->format, "|");
	while (temp->ways[--flag] != '|' && temp->ways[flag])
		temp->ways[flag] = ' ';
	if (ft_strlen(temp->ways) > ft_strlen(temp->format))
		search(temp);
	free(cut);
	free(str);
}
