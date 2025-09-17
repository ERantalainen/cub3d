/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:59:56 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 14:44:09 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	ft_look_right(t_data *data, double rot)
{
	double	temp_x;

	temp_x = data->player.pdx;
	data->player.pdx = data->player.pdx * cos(-rot) - data->player.pdy
		* sin(-rot);
	data->player.pdy = temp_x * sin(-rot) + data->player.pdy * cos(-rot);
	temp_x = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(-rot) - data->player.planeY
		* sin(-rot);
	data->player.planeY = temp_x * sin(-rot) + data->player.planeY * cos(-rot);
	data->player.dir[0] -= rot;
	if (data->player.dir[0] < 0)
		data->player.dir[0] += 2 * PI;
}

void	ft_look_left(t_data *data, double rot)
{
	double	temp_x;

	temp_x = data->player.pdx;
	data->player.pdx = data->player.pdx * cos(rot) - data->player.pdy
		* sin(rot);
	data->player.pdy = temp_x * sin(rot) + data->player.pdy * cos(rot);
	temp_x = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(rot) - data->player.planeY
		* sin(rot);
	data->player.planeY = temp_x * sin(rot) + data->player.planeY * cos(rot);
	data->player.dir[0] += rot;
	if (data->player.dir[0] > 2 * PI)
		data->player.dir[0] -= 2 * PI;
}

void	cursor_pos(double xpos, double ypos, void *param)
{
	t_data	*data;
	double	new_pos;

	data = (t_data *)param;
	if (xpos < WIDTH / 2)
	{
		ft_look_left(data, ROT / 2);
		xpos += xpos / 4;
		new_pos = xpos;
		if (new_pos > WIDTH / 2)
			new_pos = WIDTH / 2;
		mlx_set_mouse_pos(data->mlx, new_pos, ypos);
	}
	else if (xpos > WIDTH / 2)
	{
		ft_look_right(data, ROT / 2);
		xpos -= xpos / 4;
		new_pos = xpos;
		if (new_pos < WIDTH / 2)
			new_pos = WIDTH / 2;
		mlx_set_mouse_pos(data->mlx, new_pos, ypos);
	}
}
