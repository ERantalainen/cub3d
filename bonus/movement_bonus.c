/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:38:21 by erantala          #+#    #+#             */
/*   Updated: 2025/09/12 16:24:37 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	ft_move_north(t_data *data, float speed)
{
	int	x;
	int	y;

	y = floor(data->player.pos[0] + data->player.pdx * (speed * 1));
	x = floor(data->player.pos[1] + data->player.pdy * (speed * 1));
	if ((data->map[y][x] != '1'))
	{
		data->player.pos[1] += data->player.pdx * speed;
		data->player.pos[0] += data->player.pdy * speed;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_south(t_data *data, float speed)
{
	int	x;
	int	y;

	y = floor(data->player.pos[0] - data->player.pdx * (speed * 1));
	x = floor(data->player.pos[1] - data->player.pdy * (speed * 1));
	if ((data->map[y][x] != '1'))
	{
		data->player.pos[1] -= data->player.pdx * speed;
		data->player.pos[0] -= data->player.pdy * speed;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_west(t_data *data, float speed)
{
	int	x;
	int	y;

	y = floor(data->player.pos[0] - data->player.planeX * (speed * 1));
	x = floor(data->player.pos[1] - data->player.planeY * (speed * 1));
	if ((data->map[y][x] != '1'))
	{
		data->player.pos[1] -= data->player.planeX * speed;
		data->player.pos[0] -= data->player.planeY * speed;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_east(t_data *data, float speed)
{
	int	x;
	int	y;

	y = floor(data->player.pos[0] + data->player.planeX * (speed * 1));
	x = floor(data->player.pos[1] + data->player.planeY * (speed * 1));
	if ((data->map[y][x] != '1'))
	{
		data->player.pos[1] += data->player.planeX * speed;
		data->player.pos[0] += data->player.planeY * speed;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}
