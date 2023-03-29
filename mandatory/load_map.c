/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:08:57 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/22 11:01:21 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_move(t_data *mlx, char flag)
{
	if (flag == 'W' && check_wall(mlx, 'W'))
		move_w(mlx);
	if (flag == 'S' && check_wall(mlx, 'S'))
		move_s(mlx);
	if (flag == 'A' && check_wall(mlx, 'A'))
		move_a(mlx);
	if (flag == 'D' && check_wall(mlx, 'D'))
		move_d(mlx);
	if (mlx->map[mlx->p_y][mlx->p_x] == 'C')
	{
		mlx->caught_collectibles++;
		mlx->map[mlx->p_y][mlx->p_x] = '0';
	}
	if (mlx->map[mlx->p_y][mlx->p_x] == 'E'
		&& mlx->caught_collectibles == mlx->total_collectibles)
	{
		ft_printf("\033[0;32m🥇Congratulations, you reached the end!🥇\033[0;37m\n");
		ft_xbutton(mlx);
	}
	return (0);
}

void	load_map(t_data *mlx, char *file)
{
	int		i;
	int		j;

	map_prepare(mlx, file);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->columns * 24,
			mlx->lines * 24, "so_long");
	i = 0;
	while (i < mlx->lines)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			insert_wall(mlx, i, j);
			insert_others(mlx, i, j);
			mlx->x += 24;
			j++;
		}
		mlx->x = 0;
		mlx->y += 24;
		i++;
	}
}
