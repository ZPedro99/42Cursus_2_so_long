/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:17:30 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/22 12:23:15 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_the_map(char **map, t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_s_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->rock_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_bl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_br);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_f_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_b_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_r_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_l_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->coll_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	free_map(map);
	free(mlx->mlx_ptr);
	exit(0);
}

int	ft_xbutton(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_s_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_bl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_br);
	mlx_destroy_image(mlx->mlx_ptr, mlx->rock_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_f_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_b_img);
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

int	free_invalid_map(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_s_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_bl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_br);
	mlx_destroy_image(mlx->mlx_ptr, mlx->rock_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_f_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_b_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_r_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_l_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->coll_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	free_elements(mlx->map);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	free_invalid_fd(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_s_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_bl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_br);
	mlx_destroy_image(mlx->mlx_ptr, mlx->rock_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_f_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_b_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_r_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_l_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->coll_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}
