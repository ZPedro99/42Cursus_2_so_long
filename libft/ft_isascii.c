/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:16:56 by string            #+#    #+#             */
/*   Updated: 2022/11/15 13:22:57 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)

{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main()
{
	char	a;

	a = 'W';
	printf("%d\n", ft_isascii(a));
	return(0);
}*/
