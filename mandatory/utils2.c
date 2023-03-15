/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:49:11 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/15 11:03:55 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_verifications(t_data *mlx)
{
	char	**map_dup;
	if(mlx->lines < 3)
	{
		ft_printf("Error (code 73): Map is too short!\n");
		return(0);
	}
	if(!line_length(mlx))
		return(0);
	if(mlx->exits != 1 || mlx->player != 1 || mlx->total_collectibles < 1)
	{
		ft_printf("Error (code 25): Invalid number of items! Check number of players, collectibles or exits!\n");
		return(0);
	}
	map_dup = duplicate_map(mlx);
	if(!valid_path(mlx, map_dup, mlx->p_x, mlx->p_y))
	{
		ft_printf("Error (code 92): Invalid path!\n");
		free_elements(map_dup);
		return(0);
	}
	free_elements(map_dup);
	return(1);
}

int	free_invalid_map(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_r_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_l_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->coll_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	free_elements(mlx->map);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}

int	mapname(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '.')
		i++;
	if(ft_strncmp((str + i), ".ber", 4) != 0)
	{
		ft_printf("Error (code 60): Invalid map name!\n");
		return(0);
	}
	return(1);
}

int	line_length(t_data *mlx)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	while(y < mlx->lines)
	{
		while(mlx->map[y][x])
			x++;
	if(x == mlx->columns)
	{
		y++;
		x = 0;
	}
	else
	{
		ft_printf("Error (code 17): Map is not rectangular!\n");
		return(0);
	}
	}
	return(1);
}

int	free_invalid_fd(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_r_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_l_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->coll_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}
