/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:59:56 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 13:14:28 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_look_left(t_data *d, double rot)
{
	double	temp_x;

	temp_x = d->player.pdx;
	d->player.pdx = d->player.pdx * cos(-rot) - d->player.pdy
		* sin(-rot);
	d->player.pdy = temp_x * sin(-rot) + d->player.pdy * cos(-rot);
	temp_x = d->player.plane_x;
	d->player.plane_x = d->player.plane_x * cos(-rot) - d->player.plane_y
		* sin(-rot);
	d->player.plane_y = temp_x * sin(-rot) + d->player.plane_y * cos(-rot);
	d->player.dir[0] -= rot;
	if (d->player.dir[0] < 0)
		d->player.dir[0] += 2 * PI;
}

void	ft_look_right(t_data *d, double rot)
{
	double	temp_x;

	temp_x = d->player.pdx;
	d->player.pdx = d->player.pdx * cos(rot) - d->player.pdy
		* sin(rot);
	d->player.pdy = temp_x * sin(rot) + d->player.pdy * cos(rot);
	temp_x = d->player.plane_x;
	d->player.plane_x = d->player.plane_x * cos(rot) - d->player.plane_y
		* sin(rot);
	d->player.plane_y = temp_x * sin(rot) + d->player.plane_y * cos(rot);
	d->player.dir[0] += rot;
	if (d->player.dir[0] > 2 * PI)
		d->player.dir[0] -= 2 * PI;
}

void	cursor_pos(double xpos, double ypos, void *param)
{
	t_data	*data;
	double	new_pos;

	data = (t_data *)param;
	if (xpos < WIDTH / 2)
	{
		ft_look_left(data, ROT / 2);
		new_pos = (xpos + xpos / 4);
		if (new_pos > WIDTH / 2)
			new_pos = WIDTH / 2;
		mlx_set_mouse_pos(data->mlx, new_pos, ypos);
	}
	else if (xpos > WIDTH / 2)
	{
		ft_look_right(data, ROT / 2);
		new_pos = (xpos - xpos / 4);
		if (new_pos < WIDTH / 2)
			new_pos = WIDTH / 2;
		mlx_set_mouse_pos(data->mlx, new_pos, ypos);
	}
}
