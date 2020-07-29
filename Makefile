# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/29 13:21:40 by tludwig           #+#    #+#              #
#    Updated: 2020/07/29 16:28:30 by tludwig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = includes/ft_printf.h

FLAGS = -Wall -Werror -Wextra -c

SRC = ft_printf.c src/aligned.c src/check_params.c src/for_c.c src/for_i_or_d.c src/for_p.c src/for_percent.c \
src/for_s.c src/for_u.c src/for_x.c src/initialization.c src/precision.c src/simplification.c \
lib/atoi.c lib/func_with_str.c lib/other_func.c lib/out.c

OBJ = ft_printf.o src/aligned.o src/check_params.o src/for_c.o src/for_i_or_d.o src/for_p.o src/for_percent.o \
src/for_s.o src/for_u.o src/for_x.o src/initialization.o src/precision.o src/simplification.o \
lib/atoi.o lib/func_with_str.o lib/other_func.o lib/out.o

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -o $@ $<

clean:
	rm -f */*.o ft_printf.o

fclean: clean
	rm -f $(NAME)
	rm -f *.out

re: fclean all
