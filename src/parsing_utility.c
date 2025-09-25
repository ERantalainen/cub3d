/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:05:09 by erantala          #+#    #+#             */
/*   Updated: 2025/09/25 19:05:41 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	parse_color_line(t_data *data, char *line, int *have_f, int *have_c)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		data->f_c = parse_color(line + 2, 'F');
		*have_f = 1;
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		data->r_c = parse_color(line + 2, 'C');
		*have_c = 1;
	}
}

static void	parse_texture_line(t_data *data, char *line)
{
	int	tex_index;
	int	count;

	while (*line == ' ' || *line == '\t')
		line++;

	if (!ft_strncmp(line, "NO", 2))
		tex_index = NO;
	else if (!ft_strncmp(line, "SO", 2))
		tex_index = SO;
	else if (!ft_strncmp(line, "WE", 2))
		tex_index = WE;
	else if (!ft_strncmp(line, "EA", 2))
		tex_index = EA;
	else
		ft_exit("Error: invalid texture identifier", 1);

	line += 2;
	count = 0;
	while (line[count] == ' ' || line[count] == '\t')
		count++;
	if (data->wall_txt[tex_index])
		ft_exit("Error: duplicate wall texture", 1);
	data->wall_txt[tex_index] = mlx_load_png(line + count);
	error_check(data->wall_txt[tex_index], tex_index);
}

void	require_assets_present(t_data *data, int have_f, int have_c)
{
	if (!data->wall_txt[NO])
		ft_exit("Error: missing north wall texture (NO)", 1);
	if (!data->wall_txt[SO])
		ft_exit("Error: missing south wall texture (SO)", 1);
	if (!data->wall_txt[WE])
		ft_exit("Error: missing west wall texture (WE)", 1);
	if (!data->wall_txt[EA])
		ft_exit("Error: missing east wall texture (EA)", 1);

	if (!have_f)
		ft_exit("Error: missing floor color (F)", 1);
	if (!have_c)
		ft_exit("Error: missing ceiling color (C)", 1);
}

int	parse_asset_line(t_data *data, char *line, int *have_f, int *have_c)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
	{
		parse_texture_line(data, line);
		return (1);
	}
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
	{
		parse_color_line(data, line, have_f, have_c);
		return (1);
	}
	else if (!ft_strncmp(line, "FT ", 3) || !ft_strncmp(line, "CT ", 3))
	{
		return (1);
	}
	else if (ft_strchr(" 01NSEW", line[0]))
		return (0);
	ft_exit("Error: invalid line in asset section of .cub file", 1);
	return (0);
}

int	flood_fill(char **map, int row, int col)
{
	if (!map[row])
		ft_exit("Invalid Map", 1);
	if (!map[row][col] || map[row][col] == ' ')
		ft_exit("Invalid Map", 1);
	if (map[row][col] == '1' || map[row][col] == 'V'
		|| map[row][col] == 'N' || map[row][col] == 'S'
		|| map[row][col] == 'E' || map[row][col] == 'W')
		return (0);
	map[row][col] = 'V';
	flood_fill(map, row + 1, col);
	flood_fill(map, row - 1, col);
	flood_fill(map, row, col + 1);
	flood_fill(map, row, col - 1);
	return (1);
}
