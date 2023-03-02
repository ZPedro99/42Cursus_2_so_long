/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:04:14 by string            #+#    #+#             */
/*   Updated: 2022/11/11 16:04:29 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)

{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main()
{
	char	a;

	a = '3';
	printf("%d\n", ft_isdigit(a));
	return(0);
}*/
