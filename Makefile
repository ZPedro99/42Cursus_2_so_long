# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:18:30 by jomirand          #+#    #+#              #
#    Updated: 2023/03/15 11:48:03 by jomirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext
RM = rm -rf

LIBFT = libft/libft.a
MLX = mandatory/minilibx-linux/libmlx_Linux.a

SRCS = 	mandatory/so_long.c\
		mandatory/load_map.c\
		mandatory/utils_map.c\
		mandatory/utils.c\
		mandatory/utils2.c\
		mandatory/utils3.c\
		mandatory/moves.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MFLAGS) -g -o so_long

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) so_long

re: fclean all