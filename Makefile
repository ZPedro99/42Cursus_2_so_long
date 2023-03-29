# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:18:30 by jomirand          #+#    #+#              #
#    Updated: 2023/03/28 15:02:05 by jomirand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext
RM = rm -rf

LIBFT = libft/libft.a
MLX = ./minilibx-linux/libmlx_Linux.a

SRCS = 	mandatory/so_long.c\
		mandatory/load_map.c\
		mandatory/moves.c\
		mandatory/utils_map.c\
		mandatory/utils.c\
		mandatory/utils2.c\
		mandatory/utils3.c\
		mandatory/utils4.c\
		mandatory/utils5.c\
		mandatory/free.c\
		mandatory/free2.c\

SRCS_BONUS = 	bonus/so_long_bonus.c\
				bonus/load_map_bonus.c\
				bonus/moves_bonus.c\
				bonus/utils_map_bonus.c\
				bonus/utils_bonus.c\
				bonus/utils2_bonus.c\
				bonus/utils3_bonus.c\
				bonus/utils4_bonus.c\
				bonus/utils5_bonus.c\
				bonus/free_bonus.c\
				bonus/free2_bonus.c\
				bonus/enemies.c\

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./minilibx-linux


$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MFLAGS) -o $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MFLAGS) -o $(NAME_BONUS)

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

clean_bonus:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS_BONUS)
	@$(RM) $(NAME_BONUS)

fclean: clean clean_bonus
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all