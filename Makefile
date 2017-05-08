# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amusel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 16:26:25 by amusel            #+#    #+#              #
#    Updated: 2017/03/31 21:08:18 by amusel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in 

CFLAGS = -Wall -Wextra -Werror

INCLUDES = .

SRCS = main.c helpme.c find.c sear.c wayss.c ant.c

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME) : $(LIBFTDIR)libftprintf.a $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o  $(NAME) -L./$(LIBFTDIR) -lftprintf
	
%.o: %.c 
	gcc $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libftprintf.a: libft/Makefile
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTDIR)libftprintf.a
	
re: fclean all

