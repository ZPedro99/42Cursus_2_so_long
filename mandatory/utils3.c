/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:47:31 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/15 10:35:21 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(t_data *mlx, char **map, int x, int y)
{
	static int	e;
	static int	c;

	if(x < 0 || y < 0 || x > mlx->columns || y > mlx->lines || map[y][x] == '1')
		return(0);
	if(map[y][x] == 'E')
	{
		//ft_printf("exit found!\n");
		e++;
	}
	if(map[y][x] == 'C')
	{
		//ft_printf("%d out of %d collectibles reached!\n", c, (mlx->total_collectibles - 1));
		c++;
	}
	map[y][x] = '1';
	/* print_map(map);
	ft_printf("\n\n"); */
	valid_path(mlx, map, x + 1, y);
	valid_path(mlx, map, x - 1, y);
	valid_path(mlx, map, x, y + 1);
	valid_path(mlx, map, x, y - 1);
	if(e == 1 && c == mlx->total_collectibles)
		return(1);
	else
		return(0);
}

char	**duplicate_map(t_data *mlx)
{
	char	**map_dup;
	char	*line;
	int		i;

	i = 0;
	map_dup = (char **)malloc(sizeof(char *) * (mlx->lines + 1));
	while(1)
	{
		line = get_next_line(mlx->fd);
		if(!line)
			break;
		map_dup[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	map_dup[i] = 0;
	return(map_dup);
}
