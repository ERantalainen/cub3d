/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:38:21 by erantala          #+#    #+#             */
/*   Updated: 2025/08/23 02:36:25 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_move_north(t_data *data)
{
	int	x;
	int	y;

		if (data->map[y][(int)data->player.pos[1]] != 1)
			data->player.pos[1] += data->player.pdx * SPEED;
		if (data->map[(int)data->player.pos[0]][x] != 1)
			data->player.pos[0] += data->player.pdy * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
}

void	ft_move_south(t_data *data)
{
	int	x;
	int	y;

		if (data->map[y][(int)data->player.pos[1]] != 1)
			data->player.pos[1] -= data->player.pdx * SPEED;
		if (data->map[(int)data->player.pos[0]][x] != 1)
			data->player.pos[0] -= data->player.pdy * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];

	return ;
}

void	ft_move_west(t_data *data)
{
	int	x;
	int	y;

		if (data->map[y][(int)data->player.pos[1]] != 1)
			data->player.pos[1] -= data->player.planeX * SPEED;
		if (data->map[(int)data->player.pos[0]][x] != 1)
			data->player.pos[0] -= data->player.planeY * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	
	return ;
}

void	ft_move_east(t_data *data)
{
	int	x;
	int	y;

		if (data->map[y][(int)data->player.pos[1]] != 1)
			data->player.pos[1] += data->player.planeX * SPEED;
		if (data->map[(int)data->player.pos[0]][x] != 1)
			data->player.pos[0] += data->player.planeY * SPEED;
		data->player.map_pos[0] = (int)data->player.pos[0];
		data->player.map_pos[1] = (int)data->player.pos[1];
	
	return ;
}
