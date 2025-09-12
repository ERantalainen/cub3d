/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:59:56 by erantala          #+#    #+#             */
/*   Updated: 2025/09/12 17:32:56 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	ft_look_left(t_data *data, double rot)
{
	double	temp_x;

	temp_x = data->player.pdx;
	data->player.pdx = data->player.pdx * cos(-rot) - data->player.pdy * sin(-rot);
	data->player.pdy = temp_x * sin(-rot) + data->player.pdy * cos(-rot);
	temp_x = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(-rot) - data->player.planeY * sin(-rot);
	data->player.planeY = temp_x * sin(-rot) + data->player.planeY * cos(-rot);
	data->player.dir[0] -= rot;
	if (data->player.dir[0] < 0)
		data->player.dir[0] += 2 * PI;
}

void	ft_look_right(t_data *data, double rot)
{
	double	temp_x;

	temp_x = data->player.pdx;
	data->player.pdx = data->player.pdx * cos(rot) - data->player.pdy * sin(rot);
	data->player.pdy = temp_x * sin(rot) + data->player.pdy * cos(rot);
	temp_x = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(rot) - data->player.planeY * sin(rot);
	data->player.planeY = temp_x * sin(rot) + data->player.planeY * cos(rot);
	data->player.dir[0] += rot;
	if (data->player.dir[0] > 2 * PI)
		data->player.dir[0] -= 2 * PI;
}

static int	updown(double ypos, t_data *data)
{
	static int	lastY = 0;

	if (ypos < lastY - 5)
	{
		lastY = ypos;
		data->player.pitch += 25;
		if (data->player.pitch > 1000)
			data->player.pitch = 1000;
		return (1);
	}
	else if (ypos > lastY + 5)
	{
		lastY = ypos;
		data->player.pitch -= 25;
		if (data->player.pitch < -1000)
			data->player.pitch = -1000;
		return (1);
	}
	return (0);
}

void	cursor_pos(double xpos, double ypos, void *param)
{
	static	int	lastX = WIDTH /2;
	t_data	*data;

	data = (t_data *)param;
	if (updown(ypos, data))
	{
		if (xpos > lastX)
			xpos -= 50;
		else if (xpos != lastX)
			xpos += 50;
	}
	if (xpos < lastX)
	{
		ft_look_left(data, ROT / 3);
		ft_look_left(data, ROT / 3);
		lastX = xpos;
	}
	else if (xpos > lastX)
	{
		ft_look_right(data, ROT / 3);
		ft_look_right(data, ROT / 3);
		lastX = xpos;
	}
}
