/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:50 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/02 09:36:41 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int keysym, t_data *mlx)
{
	//printf("%i\n", keysym);
	if(keysym == ESC)
		ft_Xbutton(mlx);
	return (0);
}

void	free_elements(t_data *mlx)
{
	int	i;

	i = 0;
	while(mlx->map[i])
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}

int	ft_Xbutton(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	free_elements(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}

void	struct_initialize(t_data *mlx)
{
	mlx->mlx_ptr = 0;
	mlx->win_ptr = 0;
	mlx->wall_img = 0;
	mlx->floor_img = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->lines = 0;
	mlx->columns = 0;
	mlx->map = 0;
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	(void)argc;
	struct_initialize(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (0);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (mlx.win_ptr == NULL)
	{
		free(mlx.win_ptr);
		return (0);
	}
	mlx.wall_img = mlx_xpm_file_to_image(mlx.mlx_ptr, WALL, &mlx.x, &mlx.y);
	mlx.floor_img = mlx_xpm_file_to_image(mlx.mlx_ptr, FLOOR, &mlx.x, &mlx.y);
	load_map(&mlx, argv);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, ft_keypress, &mlx);
	mlx_hook(mlx.win_ptr, DestroyNotify, ButtonPressMask, ft_Xbutton, &mlx);
	mlx_loop(mlx.mlx_ptr);
}