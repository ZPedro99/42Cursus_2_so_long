/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:58:44 by string            #+#    #+#             */
/*   Updated: 2022/11/16 15:54:57 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)

{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "O Andre e um chato do crl";
	printf("\nBefore memset(): %s\n", str);

	ft_memset(str + 22, '*', 3);

	printf("After memset():  %s\n", str);
	return 0;
} */
