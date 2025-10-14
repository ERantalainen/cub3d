/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:24:13 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 12:24:24 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	validate_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_strchr(" 01NSEW", line[i]))
			ft_exit("Error: invalid character in map", 1);
		i++;
	}
}

unsigned int	parse_color(char *s)
{
	char			**rgb;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				i;

	while (*s == ' ' || *s == '\t')
		s++;
	rgb = ft_split(s, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		ft_exit("Error: invalid color format", 1);
	r = (unsigned int)ft_atoi(rgb[0]);
	g = (unsigned int)ft_atoi(rgb[1]);
	b = (unsigned int)ft_atoi(rgb[2]);
	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
	if (r > 255 || g > 255 || b > 255)
		ft_exit("Error: color values must be between 0 and 255", 1);
	return (make_color(r, g, b, 255));
}

static void	parse_assets(t_data *data, char **lines, int *map_start)
{
	int		j;
	int		have_f;
	int		have_c;
	char	*line;

	have_f = 0;
	have_c = 0;
	j = 0;
	while (lines[j])
	{
		line = lines[j];
		if (line[0] == '\0')
		{
			free(line);
			j++;
			continue ;
		}
		if (!parse_asset_line(data, line, &have_f, &have_c))
			break ;
		free(line);
		j++;
	}
	*map_start = j;
	require_assets_present(data, j, lines);
}

static void	parse_map(t_data *data, char **lines, int start)
{
	int	i;
	int	j;
	int	map_lines;

	map_lines = count_map_lines(lines, start);
	data->map = malloc(sizeof(char *) * (map_lines + 1));
	if (!data->map)
		ft_exit("Error allocating map array", 1);
	i = 0;
	j = start;
	while (lines[j])
	{
		validate_map_line(lines[j]);
		data->map[i] = ft_strdup(lines[j]);
		if (!data->map[i])
			ft_exit("Error duplicating map line", 1);
		free(lines[j]);
		i++;
		j++;
	}
	data->map[i] = NULL;
	data->map_h = map_lines;
}

void	parse_cub_file(t_data *data, const char *filename)
{
	char	**lines;
	int		map_start;

	lines = read_lines(filename);
	if (!lines || !lines[0])
	{
		ft_exit("Error: empty .cub file", 1);
	}
	parse_assets(data, lines, &map_start);
	parse_map(data, lines, map_start);
	free(lines);
}
