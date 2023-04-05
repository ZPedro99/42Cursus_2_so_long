/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:53:37 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/16 13:31:23 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*result;
	int		start;
	int		end;

	start = 0;
	if (!str)
		return (0);
	end = ft_strlen((char *)str);
	while (str[start] && ft_strchr((char *)set, str[start]))
		start++;
	while (end > start && ft_strchr((char *)set, str[end - 1]))
		end--;
	result = ft_substr(str, start, (end - start));
	return (result);
}

/* #include <stdio.h>

int	main()

{
	char str[] = "abcnao tenho nada abc";

	printf("%s\n", ft_strtrim(str, "abc"));
	return(0);
} */
