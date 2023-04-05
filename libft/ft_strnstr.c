/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:49:22 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/16 14:05:49 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)

{
	size_t	i;
	size_t	j;

	i = 0;
	if (sub[0] == '\0' || !len)
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] && sub[j] && str[i + j] == sub[j] && i + j < len)
			j++;
		if (sub[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main()

{
	char	str[] = "tinhas de mandar";
	char	sub[] = "de";

	if(ft_strnstr(str, sub, 5))
		printf("%s\n", ft_strnstr(str, sub, 5));
	else
		printf("erro");
	return(0);
} */
