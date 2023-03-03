/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:45:52 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/16 18:09:22 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)

{
	while (*str != c && *str != '\0')
		str++;
	if (*str == '\0')
	{
		if (c != '\0')
			return (NULL);
		else
			return ((char *)str);
	}
	return ((char *)str);
}

/* #include <stdio.h>

int	main()

{
	char	str[] = "boas a todos";
	char	c = 'a';

	printf("Depois do |%c| temos - |%s|\n", c, ft_strchr(str, c));
	return(0);
} */
