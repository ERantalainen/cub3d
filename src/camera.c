/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:59:56 by erantala          #+#    #+#             */
/*   Updated: 2025/08/22 02:49:24 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_look_right(t_data *data)
{
	double	temp_x;

	temp_x = data->player.pdx;
	data->player.pdx = data->player.pdx * cos(-ROT) - data->player.pdy * sin(-ROT);
	data->player.pdy = temp_x * sin(-ROT) + data->player.pdy * cos(-ROT);
	temp_x = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(-ROT) - data->player.planeY * sin(-ROT);
	data->player.planeY = temp_x * sin(-ROT) + data->player.planeY * cos(-ROT);
	data->player.dir[0] -= ROT;
	if (data->player.dir[0] < 0)
		data->player.dir[0] += 2 * PI;
}

void	ft_look_left(t_data *data)
{
	double	temp_x;
	
	temp_x = data->player.pdx;
	data->player.pdx = data->player.pdx * cos(ROT) - data->player.pdy * sin(ROT);
	data->player.pdy = temp_x * sin(ROT) + data->player.pdy * cos(ROT);
	temp_x = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(ROT) - data->player.planeY * sin(ROT);
	data->player.planeY = temp_x * sin(ROT) + data->player.planeY * cos(ROT);
	data->player.dir[0] += ROT;
	if (data->player.dir[0] > 2 * PI)
		data->player.dir[0] -= 2 * PI;
}


