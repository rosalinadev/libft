# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:53:36 by rvandepu          #+#    #+#              #
#    Updated: 2024/01/22 12:30:51 by rvandepu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRC  := ft_isalpha.c \
		ft_iswhitespace.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJ := $(SRC:%.c=%.o)

LIB_DIR := ft_printf
LIB		:= libftprintf.a
LIB_PATH = $(LIB_DIR)/$(LIB)

CPPFLAGS += -I.
CFLAGS   += -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) -f $(NAME)

re: fclean all

$(LIB_PATH):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ) | $(LIB_PATH)
	$(AR) rcs $@ $^
	printf "OPEN $@\nADDLIB $(LIB_PATH)\nSAVE\nEND" | $(AR) -M
