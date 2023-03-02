/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:28:34 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/01 15:11:36 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//includes

# include "libft/libft.h"
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

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define ESC 65307
# define WALL "./textures/wall_square.xpm"
# define FLOOR "./textures/floor.xpm"
# define PLAYER ""
# define CONSUMABLE ""
# define EXIT ""

//struct

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*floor_img;
	int		x;
	int		y;
	int		lines;
	int		columns;
	char	**map;
}				t_data;

//functions

int		ft_Xbutton(t_data *mlx);
int		ft_keypress(int keysym, t_data *mlx);

//load_map

void	load_map(t_data *mlx, char **argv);

//get_next_line

char	*get_next_line(int fd);

#endif