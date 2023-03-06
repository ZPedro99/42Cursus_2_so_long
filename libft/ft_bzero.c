/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:09:37 by string            #+#    #+#             */
/*   Updated: 2022/11/16 15:04:12 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)

{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "O Andre e um chato do crl";
	printf("\nBefore memset: %s\n", str);
	ft_bzero(str, sizeof(str));
	printf("\nAfter memset: %s\n", str);
	return(0);
} */
