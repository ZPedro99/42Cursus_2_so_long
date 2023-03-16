/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:49:11 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/16 17:00:59 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_verifications(t_data *mlx)
{
	if(mlx->lines < 3)
	{
		ft_putstr_fd("Error\nMap is too short!\n", 2);
		return(0);
	}
	if(!line_length(mlx))
		return(0);
	if(mlx->exits != 1 || mlx->player != 1 || mlx->total_collectibles < 1)
	{
		ft_putstr_fd("Error\nInvalid number of items!\n", 2);
		return(0);
	}
	if(!closed_map(mlx))
	{
		ft_putstr_fd("Error\nMap is not closed!\n", 2);
		return(0);
	}
	if(!map_verifications2(mlx))
		return(0);
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
		ft_putstr_fd("Error\nInvalid map name!\n", 2);
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
		ft_putstr_fd("Error\nMap is not rectangular!\n", 2);
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
