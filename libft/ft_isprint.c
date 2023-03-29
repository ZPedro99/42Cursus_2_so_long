/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:27:14 by string            #+#    #+#             */
/*   Updated: 2022/11/07 12:00:43 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)

{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main()
{
	char	a;

	a = 'W';
	printf("%d\n", ft_isprint(a));
	return(0);
}*/
