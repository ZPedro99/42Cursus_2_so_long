/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:18:29 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/15 14:06:44 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	ft_function(unsigned int i, char *str)

{
	i = 0;

	if(str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
}

#include <stdio.h>

int	main()

{
	char	str[] = "punk";

	printf("%s\n", str);
	ft_striteri(str, ft_function);
	printf("%s\n", str);
	return(0);
} */
