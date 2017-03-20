/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:43:24 by amusel            #+#    #+#             */
/*   Updated: 2016/12/07 15:16:17 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**ret;
	int		count;

	i = 0;
	if (!s)
		return (0);
	count = ft_cwords(s, c);
	ret = (char **)malloc(sizeof(*ret) * (count + 1));
	if (!ret)
		return (NULL);
	while (i < count)
	{
		while (*s == c && *s != 0)
			s++;
		ret[i] = ft_strsub(s, 0, ft_strclen(s, c));
		if (!ret[i])
			return (0);
		s += ft_strclen((char *)s, c);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
