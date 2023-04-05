# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:16:42 by jomirand          #+#    #+#              #
#    Updated: 2023/02/23 17:54:00 by jomirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalnum.c \
        ft_isalpha.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_isascii.c \
        ft_strlen.c \
        ft_memset.c \
        ft_bzero.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_atoi.c \
        ft_strncmp.c \
        ft_memcpy.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memmove.c \
        ft_strnstr.c \
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
        ft_lstadd_back.c \
        ft_lstadd_front.c \
        ft_lstclear.c \
        ft_lstdelone.c \
        ft_lstiter.c \
        ft_lstlast.c \
        ft_lstmap.c \
        ft_lstnew.c \
        ft_lstsize.c \
        ft_printf.c \
        ft_print_address.c \
        ft_print_char.c \
        ft_print_hexa.c \
        ft_print_numbs.c \
        ft_print_string.c \
        ft_print_unsigned.c \
        get_next_line.c \
        get_next_line_bonus.c \
        get_next_line_utils.c \
        get_next_line_utils_bonus.c \

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all