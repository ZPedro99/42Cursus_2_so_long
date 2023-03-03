/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:01:38 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/17 10:08:32 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

static int	wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		wdcount;
	int		j;

	j = 0;
	if (!s)
		return (0);
	wdcount = countwords((char *)s, c);
	words = malloc(sizeof(char *) * (wdcount + 1));
	if (!words)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			words[j] = ft_substr(s, 0, wordlen(s, c));
			j++;
		}
		while (*s && *s != c)
			s++;
	}
	words[j] = 0;
	return (words);
}

/* #include <stdio.h>

int	main()

{
	char *text = "split muito dificil fds";
	char delimiter = ' ';
	char **array;
	int size;
	int i;
	i = 0;
	size = 3;

	array = ft_split(text, delimiter);

	while (i <= size)
	{
		printf("%s\n", array[i]);
		i++;
	}

	return (0);
} */
