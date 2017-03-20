/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:26:27 by amusel            #+#    #+#             */
/*   Updated: 2017/02/05 18:42:40 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

struct			s_lis
{
	int			c;
	int			cflag;
	int			j;
	int			width;
	int			prec;
	char		flag;
	char		specflag[2];
	char		*str;
	char		type[3];
	char		mod[6];
	wchar_t		*lsc;
	int			lscpoint;
	int			lscwidth;
	int			lscprec;
	int			ret;
};

char			*sc(va_list ap, struct s_lis *temp);
int				ft_printf(const char *restrict str, ...);
char			*solve(va_list ap, struct s_lis *temp, char *ret);
char			*idu(va_list ap, struct s_lis *temp);
char			*width(struct s_lis *temp, char *str);
char			*precision(struct s_lis *temp, char *str);
int				manageintmod(char *str, int *i, char *ret, struct s_lis *temp);
char			*ft_itoa_base_ll(long long int value, long long int base);
char			*ox(va_list ap, struct s_lis *temp);
char			*manageoflags(va_list ap, struct s_lis *temp);
char			*managexflags(va_list ap, struct s_lis *temp);
char			*ft_itoa_base_unsig(unsigned long long int value, int base);
int				help(struct s_lis *temp, char *ret);
int				specflag(const char *p, int *i, struct s_lis *temp, va_list ap);
void			clcsls(va_list ap, struct s_lis *temp, wchar_t *tmp);
int				lsc2(struct s_lis *temp, int k, int i, int width);
char			*solvenorm(struct s_lis *temp, char *ret, char *str);
char			*flagsnorm(struct s_lis *temp, char *str);
void			clr(struct s_lis *temp);
char			*fucking(char *ret, char *buf);
#endif
