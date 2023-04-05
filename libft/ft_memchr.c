/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:16:15 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/16 15:27:14 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)

{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((unsigned char *)str + i);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main()

{
	char	str[] = "broken strings";
	char	c = 'o';

	printf("%s\n", (char *)ft_memchr(str, c, sizeof(str)));
	return(0);
} */
