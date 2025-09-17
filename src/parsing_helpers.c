/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:38:57 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 15:48:55 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	count_map_lines(char **lines, int start)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	while (lines[j])
	{
		if (lines[j][0] == '\0')
			ft_exit("Error: empty line inside map", 1);
		i++;
		j++;
	}
	if (i == 0)
		ft_exit("Error: no map data found", 1);
	return (i);
}

static char	*read_file_to_string(const char *filename)
{
	int		fd;
	char	*line;
	char	*file_str;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit("Error opening file", 1);
	file_str = ft_strdup("");
	if (!file_str)
		ft_exit("Error allocating file buffer", 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strjoin(file_str, line);
		if (!tmp)
			ft_exit("Error joining file string", 1);
		free(file_str);
		file_str = tmp;
		free(line);
	}
	close(fd);
	return (file_str);
}

char	**read_lines(const char *filename)
{
	char	*file_str;
	char	**lines;

	file_str = read_file_to_string(filename);
	if (!file_str || file_str[0] == '\0')
	{
		free(file_str);
		return (NULL);
	}
	lines = ft_split(file_str, '\n');
	free(file_str);
	return (lines);
}
