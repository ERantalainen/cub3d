/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:17:59 by erantala          #+#    #+#             */
/*   Updated: 2025/09/12 14:18:15 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_move_north(t_data *data)
{
	int	x;
	int	y;

	y = floor(data->player.pos[0] + data->player.pdy * SPEED);
	x = floor(data->player.pos[1] + data->player.pdx * SPEED);
	if (y >= 0 && y < data->map_h && x >= 0 && x < (int)ft_strlen(data->map[y])
		&& data->map[y][x] != '1')
	{
		data->player.pos[0] += data->player.pdy * SPEED;
		data->player.pos[1] += data->player.pdx * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_south(t_data *data)
{
	int	x;
	int	y;

	y = floor(data->player.pos[0] - data->player.pdy * SPEED);
	x = floor(data->player.pos[1] - data->player.pdx * SPEED);
	if (y >= 0 && y < data->map_h && x >= 0 && x < (int)ft_strlen(data->map[y])
		&& data->map[y][x] != '1')
	{
		data->player.pos[0] -= data->player.pdy * SPEED;
		data->player.pos[1] -= data->player.pdx * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_west(t_data *data)
{
	int	x;
	int	y;

	y = floor(data->player.pos[0] - data->player.planeY * SPEED);
	x = floor(data->player.pos[1] - data->player.planeX * SPEED);
	if (y >= 0 && y < data->map_h && x >= 0 && x < (int)ft_strlen(data->map[y])
		&& data->map[y][x] != '1')
	{
		data->player.pos[0] -= data->player.planeY * SPEED;
		data->player.pos[1] -= data->player.planeX * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_east(t_data *data)
{
	int	x;
	int	y;

	y = floor(data->player.pos[0] + data->player.planeY * SPEED);
	x = floor(data->player.pos[1] + data->player.planeX * SPEED);
	if (y >= 0 && y < data->map_h && x >= 0 && x < (int)ft_strlen(data->map[y])
		&& data->map[y][x] != '1')
	{
		data->player.pos[0] += data->player.planeY * SPEED;
		data->player.pos[1] += data->player.planeX * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}
