/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:03:40 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/22 12:58:00 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_image(t_data *mlx)
{
	mlx->wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL,
			&mlx->x, &mlx->y);
	mlx->wall_s_img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL_S,
			&mlx->x, &mlx->y);
	mlx->corner_tl = mlx_xpm_file_to_image(mlx->mlx_ptr, CORNER_TL,
			&mlx->x, &mlx->y);
	mlx->corner_tr = mlx_xpm_file_to_image(mlx->mlx_ptr, CORNER_TR,
			&mlx->x, &mlx->y);
	mlx->corner_bl = mlx_xpm_file_to_image(mlx->mlx_ptr, CORNER_BL,
			&mlx->x, &mlx->y);
	mlx->corner_br = mlx_xpm_file_to_image(mlx->mlx_ptr, CORNER_BR,
			&mlx->x, &mlx->y);
	mlx->rock_img = mlx_xpm_file_to_image(mlx->mlx_ptr, ROCK,
			&mlx->x, &mlx->y);
	xpm_to_image2(mlx);
}

void	xpm_to_image2(t_data *mlx)
{
	mlx->floor_img = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR,
			&mlx->x, &mlx->y);
	mlx->char_f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, CHARACTER_W,
			&mlx->x, &mlx->y);
	mlx->char_r_img = mlx_xpm_file_to_image(mlx->mlx_ptr, CHARACTER_D,
			&mlx->x, &mlx->y);
	mlx->char_l_img = mlx_xpm_file_to_image(mlx->mlx_ptr, CHARACTER_A,
			&mlx->x, &mlx->y);
	mlx->char_b_img = mlx_xpm_file_to_image(mlx->mlx_ptr, CHARACTER_S,
			&mlx->x, &mlx->y);
	mlx->coll_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLECTIBLE,
			&mlx->x, &mlx->y);
	mlx->exit_img = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT,
			&mlx->x, &mlx->y);
}

int	check_invalid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_letters("01CEP", map[i][j]))
			{
				ft_putstr_fd("\033[0;31mError\nWrong characters!❌\033[0;37m\n", 2);
				free_elements(map);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	map_prepare(t_data *mlx, char *file)
{
	char	*line;

	line = NULL;
	mlx->x = 0;
	mlx->y = 0;
	mlx->lines = 0;
	mlx->fd = open(file, O_RDONLY);
	if (mlx->fd < 0)
	{
		ft_putstr_fd("\033[0;31mError\nInvalid file descriptor!❌\033[0;37m\n", 2);
		free_invalid_fd(mlx);
	}
	mlx->lines = line_count(line, mlx->fd);
	close(mlx->fd);
	mlx->fd = open(file, O_RDONLY);
	mlx->map = map_fill(mlx->fd, line, mlx);
	mlx->columns = ft_len(mlx->map[0]);
	player_coordinates(mlx);
	close(mlx->fd);
	mlx->fd = open(file, O_RDONLY);
	if (!map_verifications(mlx))
	{
		free_invalid_map(mlx);
		return ;
	}
}

void	insert_wall(t_data *mlx, int i, int j)
{
	if (mlx->map[i][j] == '1')
	{
		if (put_walls(mlx, i, j))
			return ;
		if (i > 0 && i < mlx->lines - 1
			&& (j == 0 || j == mlx->columns - 1))
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->wall_s_img, mlx->x, mlx->y);
		else if (i > 0 && i < mlx->lines - 1
			&& (j > 0 && j < mlx->columns - 1))
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->rock_img, mlx->x, mlx->y);
		else
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->wall_img, mlx->x, mlx->y);
	}
}
