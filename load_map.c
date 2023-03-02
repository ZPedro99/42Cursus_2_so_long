/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:08:57 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/01 15:16:30 by jomirand         ###   ########.fr       */
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

void	load_map(t_data *mlx, char **argv)
{
	int		fd;
	int	i;
	int	j;
	char	*line;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	line = NULL;
	mlx->x = 0;
	mlx->y = 0;
	mlx->lines = 0;
	fd = open(argv[1], O_RDONLY);
	mlx->lines = line_count(line, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	mlx->map = map_fill(fd, line, mlx);
	i = 0;
	while(i < mlx->lines)
	{
		j = 0;
		while(mlx->map[i][j] != '\0')
		{
			if(mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->wall_img, mlx->x, mlx->y);
			if(mlx->map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor_img, mlx->x, mlx->y);
			mlx->x += 64;
			j++;
		}
		mlx->x = 0;
		mlx->y += 64;
		i++;
	}
}