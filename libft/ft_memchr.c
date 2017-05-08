/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:52:53 by amusel            #+#    #+#             */
/*   Updated: 2016/12/07 15:46:51 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int c, size_t n)
{
	unsigned char *in;
	unsigned char k;

	in = (unsigned char *)dest;
	k = (unsigned char)c;
	while (n-- > 0)
	{
		if (*in == k)
			return (in);
		in++;
	}
	return (NULL);
}
