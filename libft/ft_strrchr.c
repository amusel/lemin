/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:29:11 by amusel            #+#    #+#             */
/*   Updated: 2016/12/02 13:56:23 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int len;

	len = ft_strlen((char *)str);
	while (len > 0 && str[len] != (char)n)
		len--;
	if (str[len] == (char)n)
		return ((char *)&str[len]);
	return (NULL);
}
