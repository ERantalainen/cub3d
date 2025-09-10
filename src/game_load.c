/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:43:47 by erantala          #+#    #+#             */
/*   Updated: 2025/09/10 14:58:20 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	find_start_pos(t_data	*data)
{
	int	row;
	int	col;

	row = 0;
	for (int i = 0; data->map[i]; i++)
		puts(data->map[i]);
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if ((data->map[row][col] == 'N' || data->map[row][col] == 'S')
			|| data->map[row][col] == 'E' || data->map[row][col] == 'W')
			{
				data->player.pos[1] = col;
				data->player.pos[0] = row;
				return (data->map[row][col]);
			}
			col++;
		}
		row++;
	}
	ft_exit("Invalid map: no start pos", 1);
	return (0);
}

void	load_game(t_data	*data)
{
	char	dir;

	dir = find_start_pos(data);
	if (dir == 'S')
	{
		data->player.dir[0] = (3 * PI / 2);
		data->player.dir[1] = 0.0;
	}
	if (dir == 'N')
	{
		data->player.dir[0] = (PI / 2);
		data->player.dir[1] = 0.0;
	}
	if (dir == 'W')
	{
		data->player.dir[0] = PI;
		data->player.dir[1] = 0.0;
	}
	if (dir == 'E')
	{
		data->player.dir[0] = 0.0;
		data->player.dir[1] = 0.0;
	}
	
	start_game(data);
}
