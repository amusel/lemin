/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:32:40 by amusel            #+#    #+#             */
/*   Updated: 2017/04/01 11:09:52 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemmi.h"

int		chek(struct s_lists *temp, char *compare, char *str)
{
	int	k;
	int	l;

	l = -1;
	k = -1;
	while (str[++k] != '-' && str[k] != '\0')
		compare[k] = str[k];
	compare[k] = '\0';
	if ((ft_strstr(temp->r, compare)) == 0)
		return (0);
	while (str[++k] != '\n' && str[k] != '\0')
		compare[++l] = str[k];
	compare[++l] = '\0';
	if ((ft_strstr(temp->r, compare)) == 0)
		return (0);
	return (1);
}

int		valid2(struct s_lists *temp, char *str, int *flag)
{
	char		*compare;
	char		*f;

	if (ft_strstr(str, "-") > 0 && ft_strstr(temp->links, str) == 0 && \
		temp->end != NULL)
	{
		f = (char *)malloc(sizeof(char *) * 2);
		f[0] = '|';
		compare = (char *)malloc(sizeof(compare) * (int)ft_strlen(str));
		if (chek(temp, compare, str) == 0)
			return (0);
		str = ft_strjoin(str, f);
		if ((ft_strstr(str, temp->end)) != 0)
			temp->links = ft_strjoin_free(&str, &temp->links);
		else
			temp->links = ft_strjoin_free(&temp->links, &str);
		free(f);
		free(compare);
	}
	else
		return (0);
	if (*flag > 0)
		return (0);
	return (1);
}

int		valid(struct s_lists *temp, char *str, int *flag)
{
	char	*f;

	f = (char *)malloc(sizeof(char *) * 2);
	f[0] = '|';
	if (*flag == 1 && temp->start == NULL && ft_strstr(temp->r, str) == 0)
	{
		*flag = -1;
		temp->start = str;
		temp->r = ft_strjoin(temp->r, temp->start);
		temp->r = ft_strjoin_free(&temp->r, &f);
	}
	else if (*flag == 2 && temp->end == NULL && ft_strstr(temp->r, str) == 0)
	{
		*flag = -1;
		validhelp(temp, str, f);
	}
	else if ((ft_strstr(str, "-") == 0) && temp->links[0] == '\0' && \
			ft_strstr(temp->r, str) == 0)
	{
		temp->r = ft_strjoin_free(&temp->r, &str);
		temp->r = ft_strjoin_free(&temp->r, &f);
	}
	else if (valid2(temp, str, flag) == 0)
		return (0);
	return (1);
}

void	manageways(struct s_lists *temp)
{
	char	*str;
	int		k;
	int		flag;

	flag = -1;
	temp->ways = (char *)malloc(sizeof(str) * 10);
	ft_strclr(temp->ways);
	str = (char *)malloc(sizeof(str) * 1000);
	while (temp->format[++flag])
	{
		if (temp->format[flag] == ' ' && temp->format[flag + 1] == ' ')
			while (temp->format[flag] != '|')
				flag++;
		k = -1;
		while (temp->format[flag] != '|')
			str[++k] = temp->format[flag++];
		if (k != -1)
		{
			str[++k] = '\0';
			temp->ways = ft_strjoin(temp->ways, str);
			temp->ways = ft_strjoin(temp->ways, "|");
			match(temp, str, flag);
		}
	}
	free(str);
}

int		main(void)
{
	struct s_lists	*temp;

	temp = (struct s_lists *)malloc(sizeof(temp) * 3000);
	temp->ants = 0;
	temp->ret = 0;
	temp->links = ft_strnew(5);
	temp->format = ft_strnew(5);
	temp->r = ft_strnew(5);
	temp->ways = ft_strnew(5);
	ft_strclr(temp->ways);
	if (input(temp, 0) == 0 || antsrd(temp, temp->r, 0) == 0 || \
		waysfind(temp->links, temp->start, temp, temp->start) == 0)
	{
		write(1, "\nERROR\n", 6);
		return (0);
	}
	write(1, "\n", 1);
	wayscomplete(temp);
	ft_putstr(temp->ways);
	write(1, "\n", 1);
	antsoutput(temp);
	temp = NULL;
	free(temp);
	return (0);
}
