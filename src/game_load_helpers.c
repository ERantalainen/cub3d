/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:43:47 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 13:47:57 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_spawn_in_row(char *row, int y, t_spawn *spawn)
{
	int	x;

	x = 0;
	while (row[x])
	{
		if (row[x] == 'N' || row[x] == 'S' || row[x] == 'E' || row[x] == 'W')
		{
			if (spawn->c == '\0')
			{
				spawn->row = y;
				spawn->col = x;
				spawn->c = row[x];
			}
			else
				ft_exit("Error: multiple player spawns found", 1);
		}
		x++;
	}
}

t_spawn	find_spawn(char **map, int map_h)
{
	int		y;
	t_spawn	spawn;

	spawn.row = -1;
	spawn.col = -1;
	spawn.c = '\0';
	y = 0;
	while (y < map_h)
	{
		check_spawn_in_row(map[y], y, &spawn);
		y++;
	}
	if (spawn.c == '\0')
		ft_exit("Error: no player spawn found", 1);
	return (spawn);
}

static void	set_player_vertical(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player.pdx = 0.0;
		data->player.pdy = -1.0;
		data->player.planeX = 0.66;
		data->player.planeY = 0.0;
	}
	else if (c == 'S')
	{
		data->player.pdx = 0.0;
		data->player.pdy = 1.0;
		data->player.planeX = -0.66;
		data->player.planeY = 0.0;
	}
}

static void	set_player_horizontal(t_data *data, char c)
{
	if (c == 'E')
	{
		data->player.pdx = 1.0;
		data->player.pdy = 0.0;
		data->player.planeX = 0.0;
		data->player.planeY = 0.66;
	}
	else if (c == 'W')
	{
		data->player.pdx = -1.0;
		data->player.pdy = 0.0;
		data->player.planeX = 0.0;
		data->player.planeY = -0.66;
	}
}

void	set_player_direction(t_data *data, char c)
{
	if (c == 'N' || c == 'S')
		set_player_vertical(data, c);
	else if (c == 'E' || c == 'W')
		set_player_horizontal(data, c);
}
