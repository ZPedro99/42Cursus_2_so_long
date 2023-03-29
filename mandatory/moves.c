/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:47:15 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/22 10:35:16 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor_img, mlx->p_x * 24, mlx->p_y * 24);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->char_f_img, mlx->p_x * 24, (mlx->p_y - 1) * 24);
	mlx->p_y -= 1;
	mlx->moves++;
	ft_printf("Number of moves: %d\n", mlx->moves);
}

void	move_s(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor_img, mlx->p_x * 24, mlx->p_y * 24);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->char_b_img, mlx->p_x * 24, (mlx->p_y + 1) * 24);
	mlx->p_y += 1;
	mlx->moves++;
	ft_printf("Number of moves: %d\n", mlx->moves);
}

void	move_a(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor_img, mlx->p_x * 24, mlx->p_y * 24);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->char_l_img, (mlx->p_x - 1) * 24, mlx->p_y * 24);
	mlx->last_side = 'A';
	mlx->p_x -= 1;
	mlx->moves++;
	ft_printf("Number of moves: %d\n", mlx->moves);
}

void	move_d(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->floor_img, mlx->p_x * 24, mlx->p_y * 24);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->char_r_img, (mlx->p_x + 1) * 24, mlx->p_y * 24);
	mlx->last_side = 'D';
	mlx->p_x += 1;
	mlx->moves++;
	ft_printf("Number of moves: %d\n", mlx->moves);
}
