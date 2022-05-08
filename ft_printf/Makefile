# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: georgy <georgy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 14:01:52 by georgy            #+#    #+#              #
#    Updated: 2022/01/21 15:00:46 by georgy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

HEADER =	include/ft_printf.h

LIST =		source/ft_printf.c	source/ft_char.c\
			source/ft_string.c	source/ft_int.c\
			source/ft_hex.c\

MAKEFILE =	Makefile

OBJ = 		$(LIST:.c=.o)

FLAGS = 	-Wall -Wextra -Werror

$(NAME) :	$(OBJ)
				ar rcs $(NAME) $?

%.o : 		%.c	$(HEADER) $(MAKEFILE)
				gcc $(FLAGS) -c $< -o $@

all :		$(NAME)

clean :
				@rm -f $(OBJ)

fclean : 	clean
				@rm -f $(NAME)

re : 		fclean all

.PHONY : 	all clean fclean re
