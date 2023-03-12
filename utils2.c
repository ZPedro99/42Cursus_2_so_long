/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:49:11 by jomirand          #+#    #+#             */
/*   Updated: 2023/03/08 14:09:16 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	map_verifications(t_data *mlx, char *str)
{
	int	i;

	i = 0;
	while(str[i] != '.')
		i++;
	if(ft_strncmp(*(str + i), ".ber", 4) != 0)
	{
		ft_printf("Map is not valid!\n");
		return(0);
	}
}
