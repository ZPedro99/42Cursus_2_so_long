/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:47:31 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/22 12:35:07 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(t_data *mlx, char **map, int x, int y)
{
	static int	e;
	static int	c;

	if (x < 0 || y < 0 || x > mlx->columns || y > mlx->lines
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
		e++;
	if (map[y][x] == 'C')
		c++;
	map[y][x] = 'X';
	valid_path(mlx, map, x + 1, y);
	valid_path(mlx, map, x - 1, y);
	valid_path(mlx, map, x, y + 1);
	valid_path(mlx, map, x, y - 1);
	if (e == 1 && c == mlx->total_collectibles)
		return (1);
	else
		return (0);
}

char	**duplicate_map(t_data *mlx)
{
	char	**map_dup;
	char	*line;
	int		i;

	i = 0;
	map_dup = (char **)malloc(sizeof(char *) * (mlx->lines + 1));
	while (1)
	{
		line = get_next_line(mlx->fd);
		if (!line)
			break ;
		map_dup[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	map_dup[i] = 0;
	return (map_dup);
}

int	closed_map(t_data *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->columns)
	{
		if (mlx->map[0][i] != '1' || mlx->map[mlx->lines - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < mlx->lines - 1)
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][mlx->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_letters(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	map_verifications2(t_data *mlx)
{
	char	**map_dup;
	int		i;
	int		j;

	map_dup = duplicate_map(mlx);
	if (!valid_path(mlx, map_dup, mlx->p_x, mlx->p_y))
	{
		ft_putstr_fd("\033[0;31mError\nInvalid path!❌\033[0;37m\n", 2);
		free_elements(map_dup);
		return (0);
	}
	i = 0;
	j = 0;
	if (!check_invalid_chars(mlx->map))
	{
		free_elements(map_dup);
		free_invalid_chars(mlx);
		return (0);
	}
	free_elements(map_dup);
	return (1);
}
