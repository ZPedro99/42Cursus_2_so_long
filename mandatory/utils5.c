/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:53:44 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/22 12:57:32 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_others(t_data *mlx, int i, int j)
{
	if (mlx->map[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->floor_img, mlx->x, mlx->y);
	if (mlx->map[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->char_r_img, mlx->x, mlx->y);
	if (mlx->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->coll_img, mlx->x, mlx->y);
	if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->exit_img, mlx->x, mlx->y);
}

int	put_walls(t_data *mlx, int i, int j)
{
	if (i == 0 && j == 0)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->corner_tl, mlx->x, mlx->y);
		return (1);
	}
	else if (i == 0 && j == mlx->columns - 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->corner_tr, mlx->x, mlx->y);
		return (1);
	}
	else if (i == mlx->lines - 1 && j == 0)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->corner_bl, mlx->x, mlx->y);
		return (1);
	}
	else if (i == mlx->lines - 1 && j == mlx->columns - 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->corner_br, mlx->x, mlx->y);
		return (1);
	}
	return (0);
}
