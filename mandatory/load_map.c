/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:08:57 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/15 17:14:13 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_move(t_data *mlx, char flag)
{
	if(flag == 'W' && check_wall(mlx, 'W'))
		move_forward(mlx);
	if(flag == 'S' && check_wall(mlx, 'S'))
		move_backwards(mlx);
	if(flag == 'A' && check_wall(mlx, 'A'))
		move_left(mlx);
	if(flag == 'D' && check_wall(mlx, 'D'))
		move_right(mlx);
	/* ft_printf("Player Coordinates Y :   %d\n", mlx->p_y);
	ft_printf("Player Coordinates X :   %d\n", mlx->p_x); */
	if(mlx->map[mlx->p_y][mlx->p_x]== 'C')
	{
		mlx->caught_collectibles++;
		//ft_printf("%d out of %d collectibles caught!\n", mlx->caught_collectibles, mlx->total_collectibles);
		mlx->map[mlx->p_y][mlx->p_x] = '0';
	}
	if(mlx->map[mlx->p_y][mlx->p_x]== 'E' && mlx->caught_collectibles == mlx->total_collectibles)
		ft_Xbutton(mlx);
	return(0);
}

void	load_map(t_data *mlx, char **argv)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;
	line = NULL;
	mlx->x = 0;
	mlx->y = 0;
	mlx->lines = 0;
	mlx->fd = open(argv[1], O_RDONLY);
	if(mlx->fd < 0)
	{
		ft_putstr_fd("Error\nInvalid file descriptor!\n", 2);
		free_invalid_fd(mlx);
	}
	mlx->lines = line_count(line, mlx->fd);
	close(mlx->fd);
	mlx->fd = open(argv[1], O_RDONLY);
	mlx->map = map_fill(mlx->fd, line, mlx);
	mlx->columns = ft_len(mlx->map[0]);
	player_coordinates(mlx);
	close(mlx->fd);
	mlx->fd = open(argv[1], O_RDONLY);
	if(!map_verifications(mlx))
	{
		free_invalid_map(mlx);
		return ;
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
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->coll_img, mlx->x, mlx->y);
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
	//ft_printf("Number of Collectibles: %d\n", mlx->total_collectibles);
}
