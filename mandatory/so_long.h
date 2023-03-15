/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:28:34 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/15 11:28:22 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//includes

# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//defines

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define WALL "./textures/brickwall.xpm"
# define FLOOR "./textures/floor.xpm"
# define CHARACTER_L "./textures/char2left.xpm"
# define CHARACTER_R "./textures/char2right.xpm"
# define COLLECTIBLE "./textures/colect.xpm"
# define EXIT "./textures/door.xpm"

//struct

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*floor_img;
	void	*char_r_img;
	void	*char_l_img;
	void	*coll_img;
	void	*exit_img;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		lines;
	int		columns;
	char	**map;
	int		total_collectibles;
	int		caught_collectibles;
	char	last_side;
	int		moves;
	int		exits;
	int		player;
	int		fd;
}				t_data;

//functions

int		ft_Xbutton(t_data *mlx);
int		ft_keypress(int keysym, t_data *mlx);

//load_map

void	load_map(t_data *mlx, char **argv);
int		do_move(t_data *mlx, char flag);

//utils

void	struct_initialize(t_data *mlx);
void	free_elements(char **map);
int		ft_keypress(int keysym, t_data *mlx);
int		ft_Xbutton(t_data *mlx);
size_t	ft_len(const char *str);

//utils2

int		map_verifications(t_data *mlx);
int		free_invalid_map(t_data *mlx);
int		mapname(char *str);
int		line_length(t_data *mlx);
int		free_invalid_fd(t_data *mlx);

//utils3

int		valid_path(t_data *mlx, char **map_dup, int x, int y);
char	**duplicate_map(t_data *mlx);

//moves

void	move_forward(t_data *mlx);
void	move_backwards(t_data *mlx);
void	move_left(t_data *mlx);
void	move_right(t_data *mlx);

//utils_map

int		line_count(char *line, int fd);
char	**map_fill(int fd, char *line, t_data *mlx);
void	player_coordinates(t_data *mlx);
int		check_wall(t_data *mlx, char flag);
void	print_map(char **map);

//get_next_line

char	*get_next_line(int fd);

#endif
