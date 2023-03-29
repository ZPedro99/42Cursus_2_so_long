/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:50:41 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/15 15:36:45 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)

{
	unsigned int	i;

	i = 0;
	if (len == 0)
		return (0);
	while ((*(str1 + i) == *(str2 + i)))
	{
		if (i == (len - 1) || *(str1 + i) == '\0' || *(str2 + i) == '\0')
			break ;
		i++;
	}
	return ((unsigned char)*(str1 + i) - (unsigned char)*(str2 + i));
}

/* #include <stdio.h>

int	main()

{
	char	str1[] = "naughty";
	char	str2[] = "maughty";

	printf("The difference between str1 and str2 is %d", ft_strncmp(str1, str2, 3));
	return(0);
} */
