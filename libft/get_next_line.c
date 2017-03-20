/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:51:39 by amusel            #+#    #+#             */
/*   Updated: 2017/01/16 16:27:46 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fill_line(int j, char **save, char **ret)
{
	int		i;
	char	*temp;
	char	*str;

	i = 0;
	temp = *save;
	while ((temp)[i] != '\n' && (temp)[i] != '\0')
		i++;
	*ret = ft_strsub(temp, 0, i);
	if ((temp)[i] == '\n')
	{
		temp = ft_strdup(&temp[i + 1]);
		free(*save);
		*save = temp;
		return (1);
	}
	if ((temp)[i] == '\0')
	{
		temp[0] = '\0';
		str = *ret;
		if (j == 0 && ft_strlen(str) == 0)
			return (2);
	}
	return (1);
}

int		get_next_line(const int fd, char **ret)
{
	int			j;
	static char	*save = "\0";
	int			k;
	char		*temp;
	char		line[BUFF_SIZE + 1];

	if (fd < 0 || !(ret) || BUFF_SIZE < 1)
		return (-1);
	while (!(ft_strchr(save, '\n')) && (j = read(fd, line, BUFF_SIZE)) > 0)
	{
		line[j] = '\0';
		temp = save;
		temp = ft_strjoin(temp, line);
		if (save[1] != '\0')
			free(save);
		save = temp;
	}
	if (j < 0)
		return (-1);
	k = fill_line(j, &save, &(*ret));
	if (j == 0 && k == 2)
		return (0);
	return (1);
}
