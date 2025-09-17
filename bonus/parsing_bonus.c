/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:24:13 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 14:48:06 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	require_assets_present(t_data *data, int have_f, int have_c)
{
	if (!data->wall_txt[NO] || !data->wall_txt[SO] || !data->ceil_txt
		|| !data->wall_txt[WE] || !data->wall_txt[EA] || !data->flr_txt)
		ft_exit("Error: missing one or more wall textures (NO/SO/WE/EA)", 1);
	if (have_f == 0 || have_c == 0)
		ft_exit("Error: missing floor or ceiling color (F/C)", 1);
}

static void	parse_texture_line(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		data->wall_txt[NO] = mlx_load_png(line + 3);
	else if (!ft_strncmp(line, "SO ", 3))
		data->wall_txt[SO] = mlx_load_png(line + 3);
	else if (!ft_strncmp(line, "WE ", 3))
		data->wall_txt[WE] = mlx_load_png(line + 3);
	else if (!ft_strncmp(line, "EA ", 3))
		data->wall_txt[EA] = mlx_load_png(line + 3);
	else if (!ft_strncmp(line, "FT ", 3))
		data->flr_txt = mlx_load_png(line + 3);
	else if (!ft_strncmp(line, "CT ", 3))
		data->ceil_txt = mlx_load_png(line + 3);
	if ((!ft_strncmp(line, "NO ", 3) && !data->wall_txt[NO])
		|| (!ft_strncmp(line, "SO ", 3) && !data->wall_txt[SO])
		|| (!ft_strncmp(line, "WE ", 3) && !data->wall_txt[WE])
		|| (!ft_strncmp(line, "EA ", 3) && !data->wall_txt[EA])
		|| (!ft_strncmp(line, "FT ", 3) && !data->flr_txt)
		|| (!ft_strncmp(line, "CT ", 3) && !data->ceil_txt))
		ft_exit("Error loading wall texture", 1);
}

static unsigned int parse_color(char *s)
{
		char			**rgb;
		unsigned int	r;
		unsigned int	g;
		unsigned int	b;
		int			 i;

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
	return make_color(r, g, b, 255);
}

static void	parse_color_line(t_data *data, char *line, int *have_f, int *have_c)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		data->f_c = parse_color(line + 2);
		*have_f = 1;
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		data->r_c = parse_color(line + 2);
		*have_c = 1;
	}
}

static void	parse_map_line(t_data *data, char *line, int *i)
{
	if (line[0] != '\0')
	{
		data->map[*i] = ft_strdup(line);
		if (!data->map[*i])
			ft_exit("Error duplicating map line", 1);
		(*i)++;
	}
}

void	parse_cub_file(t_data *data, const char *filename)
{
	char	**lines;
	int		line_count;
	int		i;
	int		j;
	int		have_f;
	int		have_c;

	lines = read_lines(filename, &line_count);
	if (line_count == 0)
		ft_exit("Error: empty .cub file", 1);
	data->map = malloc(sizeof(char *) * (line_count + 1));
	if (!data->map)
		ft_exit("Error allocating map array", 1);
	i = 0;
	have_f = 0;
	have_c = 0;
	j = 0;
	while (j < line_count)
	{
		char *line = lines[j];

		if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
			|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
			parse_texture_line(data, line);
		else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
			parse_color_line(data, line, &have_f, &have_c);
		else if (!ft_strncmp(line, "FT ", 3) || !ft_strncmp(line, "CT ", 3))
		{
			parse_texture_line(data, line);
		}
		else
			parse_map_line(data, line, &i);
		free(line);
		j++;
	}
	free(lines);
	data->map[i] = NULL;
	data->map_h = i;
	if (data->map_h == 0)
		ft_exit("Error: no map data found in .cub", 1);
	require_assets_present(data, have_f, have_c);
}
