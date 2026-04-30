/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakhatoo <nakhatoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 14:28:48 by nakhatoo      #+#    #+#                 */
/*   Updated: 2026/04/15 17:25:47 by nakhatoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cutline(const char *stash)
{
	char	*newline;
	size_t	len;

	newline = gnl_strchr(stash, ',');
	if (newline)
		len = (size_t)(newline - stash) + 1;
	else
		len = gnl_strlen(stash);
	if (len == 0)
		return (NULL);
	return (gnl_substr(stash, 0, len));
}

static char	*trim_stash(char *stash)
{
	char	*newline;
	char	*rest;

	newline = gnl_strchr(stash, ',');
	if (!newline)
	{
		free(stash);
		return (NULL);
	}
	rest = gnl_substr(stash, (unsigned int)(newline - stash) + 1,
			gnl_strlen(newline + 1));
	free(stash);
	if (rest && rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

static char	*read_and_join(int fd, char	*stash, ssize_t	*bytes)
{
	char	*buf;
	char	*temp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free(stash);
		return (NULL);
	}
	*bytes = read(fd, buf, BUFFER_SIZE);
	if (*bytes < 0)
	{
		free(buf);
		free(stash);
		return (NULL);
	}
	buf[*bytes] = '\0';
	temp = stash;
	stash = gnl_strjoin(temp, buf);
	free(buf);
	free(temp);
	return (stash);
}

static char	*read_stash(int fd, char *stash)
{
	ssize_t	bytes;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	bytes = 1;
	while (!gnl_strchr(stash, ',') && bytes > 0)
	{
		stash = read_and_join(fd, stash, &bytes);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = cutline(stash);
	stash = trim_stash(stash);
	return (line);
}
