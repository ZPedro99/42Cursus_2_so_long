/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:50 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/13 11:48:41 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	mlx;

	if(argc != 2)
		return(0);
	if(!mapname(argv[1]))
		return(0);
	struct_initialize(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (0);
	mlx.wall_img = mlx_xpm_file_to_image(mlx.mlx_ptr, WALL, &mlx.x, &mlx.y);
	mlx.floor_img = mlx_xpm_file_to_image(mlx.mlx_ptr, FLOOR, &mlx.x, &mlx.y);
	mlx.char_r_img = mlx_xpm_file_to_image(mlx.mlx_ptr, CHARACTER_R, &mlx.x, &mlx.y);
	mlx.char_l_img = mlx_xpm_file_to_image(mlx.mlx_ptr, CHARACTER_L, &mlx.x, &mlx.y);
	mlx.coll_img = mlx_xpm_file_to_image(mlx.mlx_ptr, COLLECTIBLE, &mlx.x, &mlx.y);
	mlx.exit_img = mlx_xpm_file_to_image(mlx.mlx_ptr, EXIT, &mlx.x, &mlx.y);
	load_map(&mlx, argv);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, ft_keypress, &mlx);
	mlx_hook(mlx.win_ptr, DestroyNotify, ButtonPressMask, ft_Xbutton, &mlx);
	mlx_loop(mlx.mlx_ptr);
}