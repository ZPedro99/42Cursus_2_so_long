/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:47:15 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/15 10:56:31 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_forward(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 40, mlx->p_y * 40);
	if(mlx->last_side == 'D')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_r_img, mlx->p_x * 40, (mlx->p_y - 1) * 40);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_l_img, mlx->p_x * 40, (mlx->p_y - 1) * 40);
	mlx->p_y -= 1;
	mlx->moves++;
	ft_printf("Number of moves: %d\n", mlx->moves);
}

void	move_backwards(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 40, mlx->p_y * 40);
	if(mlx->last_side == 'D')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_r_img, mlx->p_x * 40, (mlx->p_y + 1) * 40);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_l_img, mlx->p_x * 40, (mlx->p_y + 1) * 40);
	mlx->p_y += 1;
	mlx->moves++;
	ft_printf("Number of moves: %d\n", mlx->moves);
}

void	move_left(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 40, mlx->p_y * 40);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_l_img, (mlx->p_x - 1) * 40, mlx->p_y * 40);
	mlx->last_side = 'A';
	mlx->p_x -= 1;
	mlx->moves++;
	ft_printf("Number of moves: %d\n", mlx->moves);
}

void	move_right(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->p_x * 40, mlx->p_y * 40);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->char_r_img, (mlx->p_x + 1) * 40, mlx->p_y * 40);
	mlx->last_side = 'D';
	mlx->p_x += 1;
	mlx->moves++;
	ft_printf("Number of moves: %d\n", mlx->moves);
}