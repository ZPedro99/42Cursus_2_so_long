/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:19:15 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/15 15:49:08 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)

{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != c && i > 0)
		i--;
	if (i == 0 && str[i] != c)
		return (0);
	return ((char *)(str + i));
}

/* #include <stdio.h>

int	main()

{
	char	str[] = "boas a todos";
	char	c = ' ';

	printf("Depois do |%c| temos - |%s|\n", c, ft_strrchr(str, c));
	return(0);
} */
