 #**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 14:07:22 by dglaser           #+#    #+#              #
#    Updated: 2018/01/01 23:01:46 by dglaser          ###   ########.fr        #
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
		ft_putwstr.c \
		ft_ismod.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar rcs $(NAME) $(OBJ) libft/*.o

#$(NAME):
#	make -C libft/
#	gcc -I ./ -c -Werror -Wextra -Wall $(SRC) -I libft/
#	ar rc $(NAME)  *.o libft/*.o

clean:
	/bin/rm -f *.o
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all
