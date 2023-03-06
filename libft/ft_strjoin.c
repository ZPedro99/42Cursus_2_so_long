/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:58:45 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/15 14:07:46 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)

{
	char	*memall;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1)
		return (NULL);
	if (!str2 && str1)
		return ((char *)str1);
	len = ft_strlen(str1) + ft_strlen(str2);
	memall = malloc(len + 1 * sizeof(char));
	if (memall == NULL)
		return (NULL);
	while (str1[i])
	{
		memall[i] = str1[i];
		i++;
	}
	while (str2[j])
		memall[i++] = str2[j++];
	memall[i] = '\0';
	return (memall);
}

/* #include <stdio.h>

int	main()

{
	char	str1[] = "nao ";
	char	str2[] = "que";

	printf("%s\n", ft_strjoin(str1, str2));
	return(0);
} */
