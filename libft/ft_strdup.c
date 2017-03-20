/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:57:55 by amusel            #+#    #+#             */
/*   Updated: 2016/12/05 19:16:38 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*strcp;

	i = 0;
	while (str[i] != 0)
		i++;
	strcp = (char *)malloc((sizeof(char)) * (i + 1));
	if (!strcp)
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		strcp[i] = str[i];
		i++;
	}
	strcp[i] = '\0';
	return (strcp);
}
