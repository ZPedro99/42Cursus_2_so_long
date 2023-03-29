/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:50 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/28 09:34:30 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	mlx;

	srand(time(0));
	(void)argv;
	if (argc != 2)
		return (0);
	if (!mapname(argv[1]))
		return (0);
	struct_initialize(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (0);
	xpm_to_image(&mlx);
	load_map(&mlx, argv[1]);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, ft_keypress, &mlx);
	mlx_hook(mlx.win_ptr, DestroyNotify, ButtonPressMask, ft_xbutton, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_animation, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
