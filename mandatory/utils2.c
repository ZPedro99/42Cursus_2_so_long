/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:49:11 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/21 17:24:29 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_verifications(t_data *mlx)
{
	if (mlx->lines < 3)
	{
		ft_putstr_fd("\033[0;31mError\nMap is too short!❌\033[0;37m\n", 2);
		return (0);
	}
	if (!line_length(mlx))
		return (0);
	if (mlx->exits != 1 || mlx->player != 1 || mlx->total_collectibles < 1)
	{
		ft_putstr_fd("\033[0;31mError\nInvalid number of items!❌\033[0;37m\n", 2);
		return (0);
	}
	if (!closed_map(mlx))
	{
		ft_putstr_fd("\033[0;31mError\nMap is not closed!❌\033[0;37m\n", 2);
		return (0);
	}
	if (!map_verifications2(mlx))
		return (0);
	return (1);
}

int	mapname(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (ft_strncmp((str + i), ".ber", 4) != 0)
	{
		ft_putstr_fd("\033[0;31mError\nInvalid map name!❌\033[0;37m\n", 2);
		return (0);
	}
	return (1);
}

int	line_length(t_data *mlx)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	while (y < mlx->lines)
	{
		while (mlx->map[y][x])
			x++;
		if (x == mlx->columns)
		{
			y++;
			x = 0;
		}
		else
		{
			ft_putstr_fd("\033[0;31mError\nMap's not rectangular!❌\033[0;37m\n", 2);
			return (0);
		}
	}
	return (1);
}
