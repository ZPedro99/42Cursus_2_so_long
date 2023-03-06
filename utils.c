/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:10:57 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/03 12:49:22 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_keypress(int keysym, t_data *mlx)
{
	//player_coordinates(mlx);
	//ft_printf("%i", keysym);
	if(keysym == ESC)
		ft_Xbutton(mlx);
	if(keysym == W)
		do_move(mlx, 'W');
	if(keysym == A)
		do_move(mlx, 'A');
	if(keysym == S)
		do_move(mlx, 'S');
	if(keysym == D)
		do_move(mlx, 'D');
	return (0);
}

int	ft_Xbutton(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_r_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_l_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->coll_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	free_elements(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}

size_t	ft_len(const char *str)

{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}