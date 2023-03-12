/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:08:57 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/08 14:08:38 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_move(t_data *mlx, char flag)
{
	if(flag == 'W' && check_wall(mlx, 'W'))
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 40, mlx->p_y * 40);
		if(mlx->last_side == 'D')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_r_img, mlx->p_x * 40, (mlx->p_y - 1) * 40);
		else
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_l_img, mlx->p_x * 40, (mlx->p_y - 1) * 40);
		mlx->p_y -= 1;
	}
	if(flag == 'A' && check_wall(mlx, 'A'))
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 40, mlx->p_y * 40);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_l_img, (mlx->p_x - 1) * 40, mlx->p_y * 40);
		mlx->last_side = 'A';
		mlx->p_x -= 1;
	}
	if(flag == 'S' && check_wall(mlx, 'S'))
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 40, mlx->p_y * 40);
		if(mlx->last_side == 'D')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_r_img, mlx->p_x * 40, (mlx->p_y + 1) * 40);
		else
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_l_img, mlx->p_x * 40, (mlx->p_y + 1) * 40);
		mlx->p_y += 1;
	}
	if(flag == 'D' && check_wall(mlx, 'D'))
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 40, mlx->p_y * 40);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_r_img, (mlx->p_x + 1) * 40, mlx->p_y * 40);
		mlx->last_side = 'D';
		mlx->p_x += 1;
	}
	/* ft_printf("Player Coordinates Y :   %d\n", mlx->p_y);
	ft_printf("Player Coordinates X :   %d\n", mlx->p_x); */
	if(mlx->map[mlx->p_y][mlx->p_x]== 'C')
	{
		mlx->caught_collectibles++;
		//ft_printf("%d out of %d collectibles caught!\n", mlx->caught_collectibles, mlx->total_collectibles);
	}
	if(mlx->map[mlx->p_y][mlx->p_x]== 'E' && mlx->caught_collectibles == mlx->total_collectibles)
	{
		ft_Xbutton(mlx);
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
	if(!map_verifications(mlx, argv[1]))
	{
		ft_Xbutton(mlx);
		return(0);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->columns * 40, mlx->lines * 40, "so_long");
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
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->coll_img, mlx->x, mlx->y);
				mlx->total_collectibles++;
			}
			if(mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->exit_img, mlx->x, mlx->y);
			mlx->x += 40;
			j++;
		}
		mlx->x = 0;
		mlx->y += 40;
		i++;
	}
	//print_map(mlx);
	player_coordinates(mlx);
	//ft_printf("Number of Collectibles: %d\n", mlx->total_collectibles);
}
