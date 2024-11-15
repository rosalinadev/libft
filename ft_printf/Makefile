# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:53:36 by rvandepu          #+#    #+#              #
#    Updated: 2024/11/15 16:27:31 by rvandepu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

FILES  := ft_printf \
		  ft_printf_variants \
		  ft_parser \
		  ft_string \
		  ft_putnbr \
		  ft_numbers \

OBJ := $(FILES:%=%.o)

LIB_DIR := ..

CPPFLAGS += -I$(LIB_DIR)
CFLAGS   += -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(AR) rcs $@ $(OBJ)
