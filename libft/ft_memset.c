/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:38:11 by amusel            #+#    #+#             */
/*   Updated: 2016/11/23 13:58:01 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int i, size_t j)
{
	unsigned char	*ptr;
	size_t			k;

	k = 0;
	ptr = (unsigned char *)str;
	while (k < j)
	{
		ptr[k] = i;
		k++;
	}
	return (str);
}
