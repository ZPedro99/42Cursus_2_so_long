/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:40:24 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/16 15:19:07 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cal_number_digits(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while ((unsigned int)n > 0)
	{
		count++;
		n = (unsigned int)n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*memall;
	int		num_dig;

	num_dig = ft_cal_number_digits(n);
	memall = malloc((num_dig + 1) * sizeof(char));
	if (n == 0)
		memall[0] = 48;
	if (memall == NULL)
		return (NULL);
	if (n < 0)
	{
		memall[0] = '-';
		n *= -1;
	}
	memall[num_dig] = '\0';
	while ((num_dig) > 0 && (unsigned int)n > 0)
	{
		memall[num_dig - 1] = ((unsigned int)n % 10) + '0';
		n = (unsigned int)n / 10;
		num_dig--;
	}
	return (memall);
}

/* #include <stdio.h>

int	main()

{
	int	n;

	n = 42;
	printf("%s\n", ft_itoa(n));
	return(0);
} */
