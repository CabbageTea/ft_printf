 #**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 14:07:22 by dglaser           #+#    #+#              #
#    Updated: 2017/12/28 11:17:05 by dglaser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ./

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
#
$(NAME): $(OBJ)
	make -C libft/
	ar rc $(NAME)  $(OBJ) libft/*.o
#$(NAME):
#	make -C libft/
#	gcc -I ./ -c -Werror -Wextra -Wall $(SRC) -I libft/
#	ar rc $(NAME)  *.o libft/*.o
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


