/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:32:43 by string            #+#    #+#             */
/*   Updated: 2022/11/07 16:27:48 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)

{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*#include <stdio.h>

int	main()
{
	char	str[] = "gato";

	printf("%d\n", ft_strlen(str));
	return(0);
}*/
