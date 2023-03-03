/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:08:57 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/03 12:53:19 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_move(t_data *mlx, int x, int y, char flag)
{
	if(mlx->map[x][y] == '0' || mlx->map[x][y] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 64, mlx->p_y * 64);
		if(flag == 'D')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_r_img, x * 64, y * 64);
		else
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_l_img, x * 64, y * 64);
		if(flag == 'W')
			mlx->p_y -= 1;
		if(flag == 'A')
			mlx->p_x -= 1;
		if(flag == 'S')
			mlx->p_y += 1;
		if(flag == 'D')
			mlx->p_x += 1;
	}
	return(0);
}

void	load_map(t_data *mlx, char **argv)
{
	int		fd;
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;
	line = NULL;
	mlx->x = 0;
	mlx->y = 0;
	mlx->lines = 0;
	fd = open(argv[1], O_RDONLY);
	mlx->lines = line_count(line, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	mlx->map = map_fill(fd, line, mlx);
	mlx->columns = ft_len(mlx->map[0]);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->columns * 64, mlx->lines * 64, "so_long");
	i = 0;
	while(i < mlx->lines)
	{
		j = 0;
		while(mlx->map[i][j] != '\0')
		{
			if(mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->wall_img, mlx->x, mlx->y);
			if(mlx->map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->x, mlx->y);
			if(mlx->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_r_img, mlx->x, mlx->y);
			if(mlx->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->coll_img, mlx->x, mlx->y);
			if(mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->exit_img, mlx->x, mlx->y);
			mlx->x += 64;
			j++;
		}
		mlx->x = 0;
		mlx->y += 64;
		i++;
	}
	print_map(mlx);
	player_coordinates(mlx);
}