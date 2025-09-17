/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:05:09 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 17:09:53 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	require_assets_present(t_data *data, int have_f, int have_c)
{
	if (!data->wall_txt[NO] || !data->wall_txt[SO] || !data->wall_txt[WE]
		|| !data->wall_txt[EA])
		ft_exit("Error: missing one or more wall textures (NO/SO/WE/EA)", 1);
	if (have_f == 0 || have_c == 0)
		ft_exit("Error: missing floor or ceiling color (F/C)", 1);
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

void	parse_color_line(t_data *data, char *line, int *have_f, int *have_c)
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

void	parse_texture_line(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		data->wall_txt[NO] = mlx_load_png(line + 3);
	else if (!ft_strncmp(line, "SO ", 3))
		data->wall_txt[SO] = mlx_load_png(line + 3);
	else if (!ft_strncmp(line, "WE ", 3))
		data->wall_txt[WE] = mlx_load_png(line + 3);
	else if (!ft_strncmp(line, "EA ", 3))
		data->wall_txt[EA] = mlx_load_png(line + 3);
	if ((!ft_strncmp(line, "NO ", 3) && !data->wall_txt[NO])
		|| (!ft_strncmp(line, "SO ", 3) && !data->wall_txt[SO])
		|| (!ft_strncmp(line, "WE ", 3) && !data->wall_txt[WE])
		|| (!ft_strncmp(line, "EA ", 3) && !data->wall_txt[EA]))
		ft_exit("Error loading wall texture", 1);
}

int	flood_fill(char **map, int row, int col)
{
	if (!map[row])
		ft_exit("Invalid Map", 1);
	if (!map[row][col] || map[row][col] == ' ')
		ft_exit("Invalid Map", 1);
	if (map[row][col] == '1' || map[row][col] == 'V')
		return (0);
	map[row][col] = 'V';
	flood_fill(map, row + 1, col);
	flood_fill(map, row - 1, col);
	flood_fill(map, row, col + 1);
	flood_fill(map, row, col - 1);
	return (1);
}
