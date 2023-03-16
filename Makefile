# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:18:30 by jomirand          #+#    #+#              #
#    Updated: 2023/03/15 12:24:55 by jomirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

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

$(MLX):
	@$(MAKE) -C ./mandatory/minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MFLAGS) -o so_long

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./mandatory/minilibx-linux
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./mandatory/minilibx-linux
	@$(RM) $(NAME) so_long

re: fclean all