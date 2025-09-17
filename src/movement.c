/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:38:21 by erantala          #+#    #+#             */
/*   Updated: 2025/08/29 16:36:18 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_move_north(t_data *data)
{
	int	x;
	int	y;

<<<<<<< Updated upstream
	y = floor(data->player.pos[1] + data->player.pdx * (SPEED * 1));
	x = floor(data->player.pos[0] + data->player.pdy * (SPEED * 1));
	if ((data->map[x][y] != '1'))
	{
		data->player.pos[1] += data->player.pdx * SPEED;
		data->player.pos[0] += data->player.pdy * SPEED;
=======
	y = floor(data->player.pos[0] + data->player.pdy * SPEED);
	x = floor(data->player.pos[1] + data->player.pdx * SPEED);
	if (y >= 0 && y < data->map_h && x >= 0 && x < (int)ft_strlen(data->map[y])
		&& data->map[y][x] != '1')
	{
		data->player.pos[0] += data->player.pdy * SPEED;
		data->player.pos[1] += data->player.pdx * SPEED;
>>>>>>> Stashed changes
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_south(t_data *data)
{
	int	x;
	int	y;

<<<<<<< Updated upstream
	y = floor(data->player.pos[1] - data->player.pdx * (SPEED * 1));
	x = floor(data->player.pos[0] - data->player.pdy * (SPEED * 1));
	if ((data->map[x][y] != '1'))
	{
		data->player.pos[1] -= data->player.pdx * SPEED;
		data->player.pos[0] -= data->player.pdy * SPEED;
=======
	y = floor(data->player.pos[0] - data->player.pdy * SPEED);
	x = floor(data->player.pos[1] - data->player.pdx * SPEED);
	if (y >= 0 && y < data->map_h && x >= 0 && x < (int)ft_strlen(data->map[y])
		&& data->map[y][x] != '1')
	{
		data->player.pos[0] -= data->player.pdy * SPEED;
		data->player.pos[1] -= data->player.pdx * SPEED;
>>>>>>> Stashed changes
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_west(t_data *data)
{
	int	x;
	int	y;

<<<<<<< Updated upstream
	y = floor(data->player.pos[1] - data->player.planeX * (SPEED * 1));
	x = floor(data->player.pos[0] - data->player.planeY * (SPEED * 1));
	if ((data->map[x][y] != '1'))
	{
		data->player.pos[1] -= data->player.planeX * SPEED;
		data->player.pos[0] -= data->player.planeY * SPEED;
=======
	y = floor(data->player.pos[0] - data->player.planeY * SPEED);
	x = floor(data->player.pos[1] - data->player.planeX * SPEED);
	if (y >= 0 && y < data->map_h && x >= 0 && x < (int)ft_strlen(data->map[y])
		&& data->map[y][x] != '1')
	{
		data->player.pos[0] -= data->player.planeY * SPEED;
		data->player.pos[1] -= data->player.planeX * SPEED;
>>>>>>> Stashed changes
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_east(t_data *data)
{
	int	x;
	int	y;

<<<<<<< Updated upstream
	y = floor(data->player.pos[1] + data->player.planeX * (SPEED * 1));
	x = floor(data->player.pos[0] + data->player.planeY * (SPEED * 1));
	if ((data->map[x][y] != '1'))
	{
		data->player.pos[1] += data->player.planeX * SPEED;
		data->player.pos[0] += data->player.planeY * SPEED;
=======
	y = floor(data->player.pos[0] + data->player.planeY * SPEED);
	x = floor(data->player.pos[1] + data->player.planeX * SPEED);
	if (y >= 0 && y < data->map_h && x >= 0 && x < (int)ft_strlen(data->map[y])
		&& data->map[y][x] != '1')
	{
		data->player.pos[0] += data->player.planeY * SPEED;
		data->player.pos[1] += data->player.planeX * SPEED;
>>>>>>> Stashed changes
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}
