/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:38:57 by erantala          #+#    #+#             */
/*   Updated: 2025/08/18 15:38:58 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <fcntl.h>

static int count_lines(const char *filename)
{
	int   fd;
	char  buf[1024];
	int   bytes;
	int   count;
	int   any_read;
	int   last_char_newline;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit("Error opening file", 1);

	count = 0;
	any_read = 0;
	last_char_newline = 0;
	while ((bytes = read(fd, buf, sizeof(buf))) > 0)
	{
		int i = 0;
		any_read = 1;
		while (i < bytes)
		{
			if (buf[i] == '\n')
				count++;
			i++;
		}
		if (buf[bytes - 1] == '\n')
			last_char_newline = 1;
		else
			last_char_newline = 0;
	}
	close(fd);

	if (any_read == 0)
		return 0;
	if (last_char_newline == 1)
		return count;
	return count + 1;
}

char **read_lines(const char *filename, int *count)
{
	int     fd;
	char    *line;
	char    **lines;
	int     n;
	int     i;

	n = count_lines(filename);
	lines = (char **)malloc(sizeof(char *) * (n + 1));
	if (!lines)
		ft_exit("Error allocating memory for map lines", 1);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit("Error opening file", 1);

	i = 0;
	while ((line = get_next_line(fd)))
	{
		size_t len = ft_strlen(line);
		if (len && line[len - 1] == '\n')
			line[len - 1] = '\0';
		lines[i] = line;
		i++;
	}
	close(fd);
	lines[i] = NULL;
	if (count)
		*count = i;
	return lines;
}
