/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:29:28 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/15 15:22:18 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))

{
	char	*memall;
	int		i;

	if (!str || !f)
		return (NULL);
	memall = malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (!memall)
		return (NULL);
	i = 0;
	while (str[i])
	{
		memall[i] = f(i, str[i]);
		i++;
	}
	memall[i] = '\0';
	return (memall);
}

/*char	function(unsigned int i, char str)

{
	(void)i;
	if(str >= 'a' && str <= 'z')
		str -= 32;
	return(str);
}
#include <stdio.h>

int	main()

{
	char	str[] = "punk";
	char	*str2;

	str2 = ft_strmapi(str, function);
	printf("%s\n", str2);
	return(0);
}*/
