 #**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 14:07:22 by dglaser           #+#    #+#              #
#    Updated: 2017/12/27 20:15:54 by dglaser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PROGRAMNAME = ft_printf

SRC =	ft_check_flags.c \
		ft_printf.c \
		ft_output.c \
		ft_letter_output.c \
		ft_digits_output.c \
		ft_base.c \
		ft_un_output.c \
		ft_prestrpad.c \
		ft_prepadding.c \
		ft_ismod.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ all
	gcc -g  -c -Werror -Wextra -Wall $(SRC) libft/libft.h
	ar rc $(NAME)  *.o libft/*.o
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


