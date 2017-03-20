/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:44:05 by amusel            #+#    #+#             */
/*   Updated: 2016/11/23 17:13:29 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *arr1;
	char *arr2;

	arr1 = dest;
	arr2 = (char *)src;
	while (*arr1)
		arr1++;
	while (*arr2)
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = 0;
	return (dest);
}
