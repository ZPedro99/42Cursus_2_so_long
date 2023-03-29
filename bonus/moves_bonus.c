/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:47:15 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/28 11:05:51 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_w(t_data *mlx)
{
	char	*move_number;

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor_img, mlx->p_x * 24, mlx->p_y * 24);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->char_f_img, mlx->p_x * 24, (mlx->p_y - 1) * 24);
	mlx->p_y -= 1;
	mlx->moves++;
	move_number = ft_itoa(mlx->moves);
	if (mlx->columns == 3)
		three_columns(mlx, move_number);
	else
	{
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->columns * 24 / 2 - 15,
			mlx->lines * 24 + 15, 0xFFFFFF, "Moves :");
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->black_img,
			mlx->columns * 24 / 2 + 35, mlx->lines * 24 + 5);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->columns * 24 / 2 + 35,
			mlx->lines * 24 + 15, 0xFFFFFF, move_number);
	}
	free(move_number);
	check_position(mlx);
	mlx->map[mlx->p_y + 1][mlx->p_x] = '0';
	mlx->map[mlx->p_y][mlx->p_x] = 'P';
}

void	move_s(t_data *mlx)
{
	char	*move_number;

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor_img, mlx->p_x * 24, mlx->p_y * 24);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->char_b_img, mlx->p_x * 24, (mlx->p_y + 1) * 24);
	mlx->p_y += 1;
	mlx->moves++;
	move_number = ft_itoa(mlx->moves);
	if (mlx->columns == 3)
		three_columns(mlx, move_number);
	else
	{
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->columns * 24 / 2 - 15,
			mlx->lines * 24 + 15, 0xFFFFFF, "Moves :");
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->black_img,
			mlx->columns * 24 / 2 + 35, mlx->lines * 24 + 5);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->columns * 24 / 2 + 35,
			mlx->lines * 24 + 15, 0xFFFFFF, move_number);
	}
	free(move_number);
	check_position(mlx);
	mlx->map[mlx->p_y - 1][mlx->p_x] = '0';
	mlx->map[mlx->p_y][mlx->p_x] = 'P';
}

void	move_a(t_data *mlx)
{
	char	*move_number;

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor_img, mlx->p_x * 24, mlx->p_y * 24);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->char_l_img, (mlx->p_x - 1) * 24, mlx->p_y * 24);
	mlx->p_x -= 1;
	mlx->moves++;
	move_number = ft_itoa(mlx->moves);
	if (mlx->columns == 3)
		three_columns(mlx, move_number);
	else
	{
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->columns * 24 / 2 - 15,
			mlx->lines * 24 + 15, 0xFFFFFF, "Moves :");
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->black_img,
			mlx->columns * 24 / 2 + 35, mlx->lines * 24 + 5);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->columns * 24 / 2 + 35,
			mlx->lines * 24 + 15, 0xFFFFFF, move_number);
	}
	free(move_number);
	check_position(mlx);
	mlx->map[mlx->p_y][mlx->p_x + 1] = '0';
	mlx->map[mlx->p_y][mlx->p_x] = 'P';
}

void	move_d(t_data *mlx)
{
	char	*move_number;

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor_img, mlx->p_x * 24, mlx->p_y * 24);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->char_r_img, (mlx->p_x + 1) * 24, mlx->p_y * 24);
	mlx->p_x += 1;
	mlx->moves++;
	move_number = ft_itoa(mlx->moves);
	if (mlx->columns == 3)
		three_columns(mlx, move_number);
	else
	{
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->columns * 24 / 2 - 15,
			mlx->lines * 24 + 15, 0xFFFFFF, "Moves :");
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->black_img,
			mlx->columns * 24 / 2 + 35, mlx->lines * 24 + 5);
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->columns * 24 / 2 + 35,
			mlx->lines * 24 + 15, 0xFFFFFF, move_number);
	}
	free(move_number);
	check_position(mlx);
	mlx->map[mlx->p_y][mlx->p_x - 1] = '0';
	mlx->map[mlx->p_y][mlx->p_x] = 'P';
}
