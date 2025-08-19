/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:38:21 by erantala          #+#    #+#             */
/*   Updated: 2025/08/19 16:38:14 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_move_north(t_data *data)
{
	int	row;
	int	col;

	row = ceil(data->player.pos[0] + 0.1);
	col = ceil(data->player.pos[1]);
	if (data->map[row][col] != ' ' && data->map[row][col] != '1')
	{
		data->player.pos[0] += 0.1;
	}
	data->player.map_pos[0] = (int)data->player.pos[0];
	data->player.map_pos[1] = (int)data->player.pos[1];
	return ;
}

void	ft_move_south(t_data *data)
{
	int	row;
	int	col;

	row = ceil(data->player.pos[0] - 0.1);
	col = ceil(data->player.pos[1]);
	if (data->map[row][col] != ' ' && data->map[row][col] != '1')
	{
		data->player.pos[0] -= 0.1;
	}
	data->player.map_pos[0] = (int)data->player.pos[0];
	data->player.map_pos[1] = (int)data->player.pos[1];
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
