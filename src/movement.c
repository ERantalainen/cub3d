/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:38:21 by erantala          #+#    #+#             */
/*   Updated: 2025/08/24 03:32:15 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_move_north(t_data *data)
{
	int	x;
	int	y;

	y = floor(data->player.pos[1] + data->player.pdx * (SPEED * 1));
	x = floor(data->player.pos[0] + data->player.pdy * (SPEED * 1));
	ft_printf("%d %d %c\n", y, x, data->map[x][y]);
	if ((data->map[x][y] != '1'))
	{
		data->player.pos[1] += data->player.pdx * SPEED;
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

	y = floor(data->player.pos[1] - data->player.pdx * (SPEED * 1));
	x = floor(data->player.pos[0] - data->player.pdy * (SPEED * 1));
	ft_printf("%d %d %c\n", y, x, data->map[x][y]);
	if ((data->map[x][y] != '1'))
	{
		data->player.pos[1] -= data->player.pdx * SPEED;
		data->player.pos[0] -= data->player.pdy * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_west(t_data *data)
{
	int	x;
	int	y;

	y = floor(data->player.pos[1] - data->player.planeX * (SPEED * 1));
	x = floor(data->player.pos[0] - data->player.planeY * (SPEED * 1));
	ft_printf("%d %d %c\n", y, x, data->map[x][y]);
	if ((data->map[x][y] != '1'))
	{
		data->player.pos[1] -= data->player.planeX * SPEED;
		data->player.pos[0] -= data->player.planeY * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}

void	ft_move_east(t_data *data)
{
	int	x;
	int	y;

	y = floor(data->player.pos[1] + data->player.planeX * (SPEED * 1));
	x = floor(data->player.pos[0] + data->player.planeY * (SPEED * 1));
	ft_printf("%d %d %c\n", y, x, data->map[x][y]);
	if ((data->map[x][y] != '1'))
	{
		data->player.pos[1] += data->player.planeX * SPEED;
		data->player.pos[0] += data->player.planeY * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	}
	return ;
}
