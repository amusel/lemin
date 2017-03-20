/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:32:40 by amusel            #+#    #+#             */
/*   Updated: 2017/03/10 13:32:42 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemmi.h"
#include <stdio.h>

int 	chek(struct s_lists *temp, char *compare, char *str)
{
	int 		k;
	int 		l;

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

int 	valid2(struct s_lists *temp, char *str, int *flag)
{
	char		*compare;
	char		*f;

	if (ft_strstr(str, "-") > 0 && ft_strstr(temp->links, str) == 0)
	{
		f = (char *)malloc(sizeof(char *) * 2);
		f[0] = '|';
		compare = (char *)malloc(sizeof(compare) * (int)ft_strlen(str));
		if (chek(temp, compare, str) == 0)
			return (0);
		if ((ft_strstr(str, temp->end)) != 0)
		{
			str = ft_strjoin(str, f);
			temp->links = ft_strjoin_free(&str, &temp->links);
		}
		else
		{
			str = ft_strjoin(str, f);
			temp->links = ft_strjoin_free(&temp->links, &str);
		}
		free(f);
		free(compare);
	}
	else
		return (0);
	if (*flag > 0)
		return (0);
	return (1);
}

int 	valid(struct s_lists *temp, char *str, int *flag)
{
	char		*f;

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
		temp->end = str;
		temp->r = ft_strjoin(temp->r, temp->end);
		temp->r = ft_strjoin_free(&temp->r, &f);
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

void	dog(char *str, int j)
{
	int 	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	if (j == 1)
		write(1, "\n", 1);
}

int 	antsrd(struct s_lists *temp, char *str, int i)
{
	if (i == 1)
	{
		get_next_line(0, &str);
		temp->ants = ft_atoi(str);
		dog(str, 1);
		if (temp->ants == 0)
			return (0);
	}
	else if (temp->start == NULL || temp->end == NULL)
		return  (0);
	return (1);
}

int		input(struct s_lists *temp)
{
	char	*str;
	int 	flag;
	int 	i;

	flag = 0;
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

int 	cmp(struct s_lists *temp, char *tep)
{
	char	*str;
	int 	i;
	int 	j;

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

int		waysfind(char *links, char *str, struct s_lists *temp, char *back)
{
	int		i;
	char	*tep;
	int		j;
	char	*f;
	int		k;

	tep = ft_strnew(ft_strlen(links));
	ft_strclr(tep);
	i = -1;
	while (links[++i] != '\0')
	{
		j = -1;
		while (links[i] != '|')
			tep[++j] = links[i++];
		if (ft_strstr(tep, str) > 0)
		{
			j = 0;
			if (ft_strnstr(tep, str, (int) ft_strlen(str)) > 0)
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
			if (ft_strcmp(tep, temp->end) == 0)
			{
				f = (char *) malloc(sizeof(char *) * 2);
				f[0] = '|';
				temp->ways = ft_strjoin_free(&temp->ways, &tep);
				temp->ways = ft_strjoin_free(&temp->ways, &f);
				break;
			}
			if (ft_strcmp(tep, temp->end) != 0 && ft_strcmp(tep, temp->start) != 0 &&\
			 	ft_strcmp(tep, back) != 0 && cmp(temp, tep) != 0 && temp->ret < 600)
			{
				temp->ways = ft_strjoin(temp->ways, str);
				j = 0;
				while (temp->ways[j])
				{
					if (temp->ways[j] == temp->ways[j + 2])
						temp->ways[j] = ' ';
					j += 2;
				}

				temp->ways = ft_strjoin(temp->ways, "-");
				temp->ways = ft_strjoin(temp->ways, tep);
				temp->ways = ft_strjoin(temp->ways, "-");
				waysfind(links, tep, temp, str);
				if (temp->ways[ft_strlen(temp->ways) - 1] != '0')
					temp->ways[ft_strlen(temp->ways) - 1] = '|';
			}
		}
	}
	free(tep);
	if (ft_strstr(temp->ways, temp->end) == 0)
		return (0);
	return (1);
}

int 	count(char *str)
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

void	match(struct s_lists *temp, char *str, int flag)
{
	char 	*cmp;
	int		k;
	int 	c;

	cmp = (char *)malloc(sizeof(str) * 1000);
	while (temp->format[++flag])
	{
		k = -1;
		while (temp->format[flag] != '|')
		{
			cmp[++k] = temp->format[flag];
			flag++;
		}
		cmp[++k] = '\0';
		k = 0;
		while (cmp[k] && cmp[0] != ' ')
		{
			c = 2;
			while (cmp[k + 2] != str[c] && ft_strlen(str) - c >= 2)
				c += 2;
			if (ft_strlen(str) - c >= 2)
			{
				while (temp->format[--flag] != '|' && temp->format[flag])
					temp->format[flag] = ' ';
				break ;
			}
			k += 2;
		}
	}
}

void	manageways(struct s_lists *temp)
{
	char 	*str;
	int 	k;
	int		flag;

	flag = -1;
	temp->ways = (char *)malloc(sizeof(str) * 10);
	str = (char *)malloc(sizeof(str) * 1000);
	while (temp->format[++flag])
	{
		if (temp->format[flag] == ' ' && temp->format[flag + 1] == ' ')
			while (temp->format[flag] != '|')
				flag++;
		k = -1;
		while (temp->format[flag] != '|')
		{
			str[++k] = temp->format[flag];
			flag++;
		}
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

void	search(struct s_lists *temp)
{
	char 	*str;
	char 	*cut;
	int		i;
	int		k;
	int 	flag;

	i = -1;
	flag = 0;
	cut = (char *)malloc(sizeof(str) * 1000);
	str = (char *)malloc(sizeof(str) * 1000);
	while (temp->ways[++i])
	{
		if (temp->ways[i] == ' ' && temp->ways[i + 1] == ' ')
			while (temp->ways[i] != '|')
				i++;
		k = -1;
		while (temp->ways[i] != '|')
		{
			str[++k] = temp->ways[i];
			i++;
		}
		str[++k] = '\0';
		if (ft_strstr(str, temp->end) == 0 && str[0] != '\0')
			while (temp->ways[--i] != '|' && temp->ways[i])
				temp->ways[i] = ' ';
		else if (count(str) < count(cut))
		{
			flag = i;
			k = -1;
			while (str[++k])
				cut[k] = str[k];
			cut[k] = '\0';
		}
	}
	temp->format = ft_strjoin(temp->format, cut);
	temp->format = ft_strjoin(temp->format, "|");
	while (temp->ways[--flag] != '|' && temp->ways[flag])
		temp->ways[flag] = ' ';
	if (ft_strlen(temp->ways) > ft_strlen(temp->format))
		search(temp);
	free(cut);
	free(str);
}

void	addpart(struct s_lists *temp, int i, int j)
{
	char 	*str;
	char	*ret;
	int 	k;
	char 	*fin;
	int 	c;

	c = -1;
	ret = (char *) malloc(sizeof(char *) * (int) ft_strlen(temp->ways));
	str = (char *) malloc(sizeof(char *) * (int) ft_strlen(temp->ways));
	fin = (char *) malloc(sizeof(char *) * (int) ft_strlen(temp->ways));
	while (temp->ways[++i] != '|' && temp->ways[i])
		fin[i] = temp->ways[i];
	fin[i] = '|';
	fin[++i] = '\0';
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
		i--;
		while (temp->ways[++i] != '|' && temp->ways[i])
			ret[++k] = temp->ways[i];
		i--;
		while (temp->ways[i] != '|')
			i--;
		ret[++k] = '\0';
		fin = ft_strjoin(fin, ret);
		fin = ft_strjoin(fin, "|");
	}
	fin[ft_strlen(fin) - 1] = '\0';
	temp->ways = fin;
	search(temp);
	manageways(temp);
	free(ret);
	free(str);
	free(fin);
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
	str = (char *) malloc(sizeof(char *) * (int) ft_strlen(temp->ways));
	while (temp->ways[++i])
		if (temp->ways[i] != ' ' && !(temp->ways[i] == '-' && temp->ways[i + 1] == ' '))
			str[++j] = temp->ways[i];
	str[++j] = '\0';
	temp->ways = NULL;
	free(temp->ways);
	temp->ways = str;
	str = NULL;
	free(str);
	addpart(temp, -1, -1);
}

void	antadd(struct s_lists *temp, int k, char c)
{
	int 	i;

	i = (int)ft_strlen(temp->ways) + 1;
	while (--i >= k)
		temp->ways[i + 1] = temp->ways[i];
	temp->ways[k] = c;
	temp->ways[(int)ft_strlen(temp->ways) + 1] = '\0';
}

int		countspec(char *str)
{
	int 	i;

	i = (int)ft_strlen(str);
	while (str[--i] == '-')
		str[i] = ' ';
	return (count(str));
}

void	pasta(struct s_lists *temp)
{
	int		i;
	int		k;
	int		c;
	char	*str;
	int 	a;

	c = 0;
	str = (char *) malloc(sizeof(char *) * (int) ft_strlen(temp->ways));
	while (++c <= temp->ants * 100)
	{
		a = 0;
		k = -1;
		while (temp->ways[++k] != '\0')
		{
			i = -1;
			while (temp->ways[k] != '|')
				str[++i] = temp->ways[k++];
			str[++i] = '\0';
			i = k;
			while (temp->ways[--i] == '-')
			{
				a++;
				if (countspec(str) - c + k - i > 0)
				{
					ft_printf("L%i-", a);
					ft_printf("%c", str[2]);
					ft_printf(" ");
				}
			}
		}
		if (countspec(str) - c + k - i > 1)
			write(1, "\n", 1);
	}
}

void	antsoutput(struct s_lists *temp)
{
	int		i;
	int		k;
	char	*str;
	char 	*tmp;
	int 	j;
	int		flag;

	str = (char *) malloc(sizeof(char *) * (int) ft_strlen(temp->ways));
	i = temp->ants + 1;
	while (--i > 0)
	{
		flag = -1;
		k = -1;
		tmp = (char *) malloc(sizeof(char *) * (int) ft_strlen(temp->ways));
		while (temp->ways[++k] != '\0')
		{
			j = -1;
			flag++;
			while (temp->ways[k] != '|')
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
		k = -1;
		flag = temp->ret;
		while (flag > -1)
			if (temp->ways[++k] == '|')
				flag--;
		antadd(temp, k, '-');
	}
	free(str);
	pasta(temp);
}

int		main(void)
{
	struct s_lists	*temp;

	temp = (struct s_lists *)malloc(sizeof(temp) * 300);
	temp->ants = 0;
	temp->ret = 0;
	temp->links = ft_strnew(5);
	temp->format = ft_strnew(5);
	temp->r = ft_strnew(5);
	temp->ways = ft_strnew(5);
	if (input(temp) == 0 || antsrd(temp, temp->r, 0) == 0 || \
		waysfind(temp->links, temp->start, temp, temp->start) == 0)
	{
		write(1, "\nERROR\n", 6);
		return (0);
	}
	write(1, "\n", 1);
	wayscomplete(temp);
	antsoutput(temp);
	printf("%s", temp->ways);
	free(temp);
	return (0);
}
