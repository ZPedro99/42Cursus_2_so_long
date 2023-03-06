/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:21:45 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/03 12:37:02 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(char *line, int fd)
{
	int	i;

	i = 0;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		free(line);
		i++;
	}
	free(line);
	return(i);
}

char	**map_fill(int fd, char *line, t_data *mlx)
{
	int	i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (mlx->lines + 1));
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	map[i] = 0;
	return(map);
}

void	player_coordinates(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->p_x = 0;
	mlx->p_y = 0;
	while(i < mlx->lines)
	{
		j = 0;
		while(mlx->map[i][j])
		{
			if(mlx->map[i][j] == 'P')
			{
				mlx->p_x = j;
				mlx->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	check_wall(t_data *mlx, char flag)
{
	//ft_printf("Player Coordinates X before move:   %d\n", mlx->p_x);
	//ft_printf("Player Coordinates Y before move:   %d\n", mlx->p_y);
	if(flag == 'W' && (mlx->map[mlx->p_y - 1][mlx->p_x]) == '1')
	{
		return(0);
	}
	if(flag == 'A' && (mlx->map[mlx->p_y][mlx->p_x - 1]) == '1')
	{
		return(0);
	}
	if(flag == 'S' && (mlx->map[mlx->p_y + 1][mlx->p_x]) == '1')
	{
		return(0);
	}
	if(flag == 'D' && (mlx->map[mlx->p_y][mlx->p_x + 1]) == '1')
	{
		return(0);
	}
	return(1);
}

void	print_map(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while(mlx->map[i])
	{
		j = 0;
		while(mlx->map[i][j])
		{
			ft_printf("%c", mlx->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}