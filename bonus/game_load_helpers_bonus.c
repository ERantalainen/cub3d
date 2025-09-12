/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:43:47 by erantala          #+#    #+#             */
/*   Updated: 2025/09/12 16:20:52 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

t_spawn	find_spawn(char **map, int map_h)
{
	int     y;
	int 	x;
	t_spawn spawn;

	spawn.row = -1;
	spawn.col = -1;
	spawn.c = '\0';

	y = 0;
	while (y < map_h)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (spawn.c == '\0')
				{
					spawn.row = y;
					spawn.col = x;
					spawn.c = map[y][x];
				}
				else
					ft_exit("Error: multiple player spawns found", 1);
			}
			x++;
		}
		y++;
	}
	if (spawn.c == '\0')
		ft_exit("Error: no player spawn found", 1);
	return spawn;
}

void	set_player_direction(t_data *data, char c)
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
	else if (c == 'E')
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
