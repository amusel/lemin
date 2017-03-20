/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:14:12 by amusel            #+#    #+#             */
/*   Updated: 2016/12/07 15:57:27 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*fresh;
	int		j;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		len--;
		i++;
	}
	j = -1;
	if (len <= 0)
		len = 0;
	if ((fresh = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	while (len-- > 0)
		fresh[++j] = s[i++];
	fresh[++j] = '\0';
	return (fresh);
}
