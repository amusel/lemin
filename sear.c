/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sear.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:10:30 by amusel            #+#    #+#             */
/*   Updated: 2017/03/31 18:10:32 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemmi.h"

void	waysfind2(char *links, char *str, struct s_lists *temp, char *back)
{
	int j;
	int k;

	if (ft_strcmp(temp->jet, temp->end) != 0 && \
		ft_strcmp(temp->jet, temp->start) != 0 &&\
		ft_strcmp(temp->jet, back) != 0 &&\
		cmp(temp, temp->jet) != 0 && temp->ret < 600)
	{
		temp->ways = ft_strjoin(temp->ways, str);
		j = 0;
		while (temp->ways[j] != '\0')
			j++;
		k = j - 1;
		while (temp->ways[k] != '-' && temp->ways[k])
			k--;
		if (temp->ways[j - 1] == temp->ways[k - 1])
			while (temp->ways[--j] != '-')
				temp->ways[j] = ' ';
		temp->ways = ft_strjoin(temp->ways, "-");
		temp->ways = ft_strjoin(temp->ways, temp->jet);
		temp->ways = ft_strjoin(temp->ways, "-");
		waysfind(links, temp->jet, temp, str);
		if (temp->ways[ft_strlen(temp->ways) - 1] != '0')
			temp->ways[ft_strlen(temp->ways) - 1] = '|';
	}
}

char	*waysfind3(char *str, char *tep)
{
	int j;
	int k;

	j = 0;
	if (ft_strnstr(tep, str, (int)ft_strlen(str)) > 0)
	{
		k = -1;
		while (tep[j] != '-')
			j++;
		while (tep[++j])
			tep[++k] = tep[j];
		tep[++k] = '\0';
	}
	else
	{
		while (tep[j] != '-')
			j++;
		tep[j] = '\0';
	}
	return (tep);
}

int		waysfind4(char *tep, struct s_lists *temp)
{
	char *f;

	if (ft_strcmp(tep, temp->end) == 0)
	{
		f = (char *)malloc(sizeof(char *) * 2);
		f[0] = '|';
		temp->ways = ft_strjoin(temp->ways, tep);
		temp->ways = ft_strjoin_free(&temp->ways, &f);
		return (0);
	}
	else
		return (1);
}

int		waysfind(char *links, char *str, struct s_lists *temp, char *back)
{
	int		i;
	char	*tep;
	int		j;

	tep = ft_strnew(ft_strlen(links) + 100);
	i = -1;
	while (links[++i] != '\0')
	{
		j = -1;
		while (links[i] != '|')
			tep[++j] = links[i++];
		tep[++j] = '\0';
		if (ft_strstr(tep, str) > 0)
		{
			tep = waysfind3(str, tep);
			if (waysfind4(tep, temp) == 0)
				break ;
			temp->jet = tep;
			waysfind2(links, str, temp, back);
		}
	}
	free(tep);
	if (ft_strstr(temp->ways, temp->end) == 0)
		return (0);
	return (1);
}

void	match2(struct s_lists *temp, char *str, int flag, char *cmp)
{
	int		k;
	int		c;
	char	*kek;

	kek = (char *)malloc(sizeof(str) * 1000);
	k = 0;
	while (cmp[k] != '-')
		k++;
	while (cmp[k] && cmp[0] != ' ')
	{
		c = -1;
		while (cmp[++k] != '-' && cmp[k])
			kek[++c] = cmp[k];
		if (cmp[k + 1] == '\0')
			break ;
		kek[++c] = '\0';
		if (ft_strstr(str, kek) != 0)
			while (temp->format[--flag] != '|' && temp->format)
				temp->format[flag] = ' ';
	}
	free(kek);
}
