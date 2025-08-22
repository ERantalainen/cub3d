/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:38:21 by erantala          #+#    #+#             */
/*   Updated: 2025/08/22 15:45:34 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_move_north(t_data *data)
{
	int	x;
	int	y;

	y = (int)data->player.pos[0] + data->player.pdx * SPEED;
	x = (int)data->player.pos[1] + data->player.pdy * SPEED;
	if (y < data->map_h && x < data->map_w)
	{
		if (data->map[y][(int)data->player.pos[1]] != 1)
			data->player.pos[1] += data->player.pdx * SPEED;
		if (data->map[(int)data->player.pos[0]][x] != 1)
			data->player.pos[0] += data->player.pdy * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_south(t_data *data)
{
	int	x;
	int	y;

	y = (int)data->player.pos[1] - data->player.pdx * SPEED;
	x = (int)data->player.pos[0] - data->player.pdy * SPEED;
	if (y < data->map_h && x < data->map_w)
	{
		if (data->map[y][(int)data->player.pos[1]] != 1)
			data->player.pos[1] -= data->player.pdx * SPEED;
		if (data->map[(int)data->player.pos[0]][x] != 1)
			data->player.pos[0] -= data->player.pdy * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_west(t_data *data)
{
	int	row;
	int	col;

	row = ceil(data->player.pos[0]);
	col = ceil(data->player.pos[1] - 0.1);
	if (data->map[row][col] != ' ' && data->map[row][col] != '1')
	{
		data->player.pos[1] -= 0.1;
	}
	data->player.map_pos[0] = (int)data->player.pos[0];
	data->player.map_pos[1] = (int)data->player.pos[1];
	return ;
}

void	ft_move_east(t_data *data)
{
	int	row;
	int	col;

	row = ceil(data->player.pos[0]);
	col = ceil(data->player.pos[1] + 0.1);
	if (data->map[row][col] != ' ' && data->map[row][col] != '1')
	{
		data->player.pos[1] += 0.1;
	}
	data->player.map_pos[0] = (int)data->player.pos[0];
	data->player.map_pos[1] = (int)data->player.pos[1];
	return ;
}
