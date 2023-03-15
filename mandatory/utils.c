/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:10:57 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/15 11:01:17 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_initialize(t_data *mlx)
{
	mlx->mlx_ptr = 0;
	mlx->win_ptr = 0;
	mlx->wall_img = 0;
	mlx->floor_img = 0;
	mlx->char_r_img = 0;
	mlx->char_l_img = 0;
	mlx->coll_img = 0;
	mlx->exit_img = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->p_x = 0;
	mlx->p_y = 0;
	mlx->lines = 0;
	mlx->columns = 0;
	mlx->map = 0;
	mlx->total_collectibles = 0;
	mlx->caught_collectibles = 0;
	mlx->last_side = 0;
	mlx->moves = 0;
	mlx->exits = 0;
	mlx->player = 0;
	mlx->fd = 0;
}

void	free_elements(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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
	free_elements(mlx->map);
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
