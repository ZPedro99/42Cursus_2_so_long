/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:08:21 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/28 11:04:04 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemies(t_data *mlx)
{
	int	move_scene;

	move_scene = rand() % 4;
	scan_for_enemies(mlx, move_scene);
}

void	scan_for_enemies(t_data *mlx, int flag)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->lines)
	{
		x = 0;
		while (x < mlx->columns)
		{
			if (mlx->map[y][x] == 'I')
			{
				enemy_move(mlx, flag, y, x);
				if (flag == 3)
					x++;
				if (flag == 2)
					y++;
			}
			x++;
		}
		y++;
	}
}

void	enemy_move(t_data *mlx, int flag, int y, int x)
{
	int	i;

	i = 0;
	if (flag == 0)
		i = do_enemy_move(mlx, 'W', y - 1, x);
	if (flag == 1)
		i = do_enemy_move(mlx, 'A', y, x - 1);
	if (flag == 2)
		i = do_enemy_move(mlx, 'S', y + 1, x);
	if (flag == 3)
		i = do_enemy_move(mlx, 'D', y, x + 1);
	if (i == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->floor_img, x * 24, y * 24);
		mlx->map[y][x] = '0';
	}
}

int	do_enemy_move(t_data *mlx, char flag, int y, int x)
{
	if (mlx->map[y][x] == '0')
	{
		put_enemy(mlx, y, x, flag);
		mlx->map[y][x] = 'I';
		return (1);
	}
	if (mlx->map[y][x] == 'P')
	{
		ft_printf("\033[0;31m💀You Died!💀\033[0;31m\n");
		ft_xbutton(mlx);
	}
	return (0);
}

void	put_enemy(t_data *mlx, int y, int x, char flag)
{
	if (flag == 'W')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->enemy_w_img, x * 24, y * 24);
	}
	if (flag == 'A')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->enemy_a_img, x * 24, y * 24);
	}
	if (flag == 'S')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->enemy_s_img, x * 24, y * 24);
	}
	if (flag == 'D')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->enemy_d_img, x * 24, y * 24);
	}
}
