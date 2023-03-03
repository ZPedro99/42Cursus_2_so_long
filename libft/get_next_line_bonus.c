/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:49:40 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/28 11:32:59 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_line_break(int fd, char *stash)
{
	char	*content_read;
	int		bytes_read;
	char	*tmp;

	content_read = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	bytes_read = 42;
	while (bytes_read != 0 && !(ft_strchr(content_read, '\n')))
	{
		bytes_read = read(fd, content_read, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (stash)
				free (stash);
			free (content_read);
			return (NULL);
		}
		*(content_read + bytes_read) = '\0';
		tmp = ft_strjoin(stash, content_read);
		free (stash);
		stash = tmp;
	}
	free (content_read);
	return (stash);
}

static char	*clean_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!(*(stash + i)))
		return (NULL);
	while (*(stash + i) != '\n' && *(stash + i) != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1 + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (*(stash + i) != '\n' && *(stash + i) != '\0')
	{
		*(line + i) = *(stash + i);
		i++;
	}
	*(line + i) = *(stash + i);
	i++;
	*(line + i) = '\0';
	return (line);
}

static char	*collect_garbage(char *stash)
{
	int		i;
	int		j;
	char	*garbage;

	i = 0;
	while (*(stash + i) != '\n' && *(stash + i) != '\0')
		i++;
	if (!(*(stash + i)) || !stash)
	{
		free (stash);
		return (NULL);
	}
	garbage = ft_calloc(sizeof(char), (ft_strlen(stash) - i));
	i++;
	j = 0;
	while (*(stash + i) != '\0')
	{
		*(garbage + j++) = *(stash + i++);
	}
	free (stash);
	return (garbage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[MAX_F_OPEN];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash[fd] = check_line_break(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = clean_line(stash[fd]);
	stash[fd] = collect_garbage(stash[fd]);
	return (line);
}
