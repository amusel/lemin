/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemmi.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:25:52 by amusel            #+#    #+#             */
/*   Updated: 2017/03/10 15:25:54 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMMI_H
# define LEMMI_H

# include "libft/libft.h"
# include "libft/ft_printf.h"

struct		s_lists
{
	char	*links;
	char	*r;
	char	*end;
	char	*start;
	int		ants;
	char	*ways;
	int		ret;
	char	*format;
	char	*jet;
	int		c;
};

void		antsoutput(struct s_lists *temp);
void		pasta(struct s_lists *temp);
int			roomout(int a, int c, char *str);
int			countspec(char *str);
void		antadd(struct s_lists *temp, int k, char c);
void		wayscomplete(struct s_lists *temp);
void		addpart(struct s_lists *temp, int i);
void		search(struct s_lists *temp);
void		manageways(struct s_lists *temp);
void		match(struct s_lists *temp, char *str, int flag);
int			count(char *str);
int			waysfind(char *links, char *str, struct s_lists *temp, char *back);
int			cmp(struct s_lists *temp, char *tep);
int			input(struct s_lists *temp, int flag);
int			antsrd(struct s_lists *temp, char *str, int i);
void		dog(char *str, int j);
int			valid(struct s_lists *temp, char *str, int *flag);
int			valid2(struct s_lists *temp, char *str, int *flag);
int			chek(struct s_lists *temp, char *compare, char *str);
void		validhelp(struct s_lists *temp, char *str, char *f);
void		match2(struct s_lists *temp, char *str, int flag, char *cmp);
#endif
