/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:59:56 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 13:02:59 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	ft_look_left(t_data *dt, double rt)
{
	double	temp_x;
	double	tmp;

	temp_x = dt->player.pdx;
	dt->player.pdx = dt->player.pdx * cos(-rt) - dt->player.pdy * sin(-rt);
	dt->player.pdy = temp_x * sin(-rt) + dt->player.pdy * cos(-rt);
	temp_x = dt->player.plane_x;
	tmp = dt->player.plane_x * cos(-rt) - dt->player.plane_y * sin(-rt);
	dt->player.plane_x = tmp;
	dt->player.plane_y = temp_x * sin(-rt) + dt->player.plane_y * cos(-rt);
	dt->player.dir[0] -= rt;
	if (dt->player.dir[0] < 0)
		dt->player.dir[0] += 2 * PI;
}

void	ft_look_right(t_data *dt, double rt)
{
	double	temp_x;
	double	tmp;

	temp_x = dt->player.pdx;
	dt->player.pdx = dt->player.pdx * cos(rt) - dt->player.pdy * sin(rt);
	dt->player.pdy = temp_x * sin(rt) + dt->player.pdy * cos(rt);
	temp_x = dt->player.plane_x;
	tmp = dt->player.plane_x * cos(rt) - dt->player.plane_y * sin(rt);
	dt->player.plane_x = tmp;
	dt->player.plane_y = temp_x * sin(rt) + dt->player.plane_y * cos(rt);
	dt->player.dir[0] += rt;
	if (dt->player.dir[0] > 2 * PI)
		dt->player.dir[0] -= 2 * PI;
}

static int	updown(double ypos, t_data *dt)
{
	static int	last_y = 0;

	if (ypos < last_y - 5)
	{
		last_y = ypos;
		dt->player.pitch += 25;
		if (dt->player.pitch > 1000)
			dt->player.pitch = 1000;
		return (1);
	}
	else if (ypos > last_y + 5)
	{
		last_y = ypos;
		dt->player.pitch -= 25;
		if (dt->player.pitch < -1000)
			dt->player.pitch = -1000;
		return (1);
	}
	return (0);
}

void	cursor_pos(double xpos, double ypos, void *param)
{
	static int	last_x = WIDTH / 2;
	t_data		*dt;

	dt = (t_data *)param;
	if (updown(ypos, dt))
	{
		if (xpos > last_x)
			xpos -= 50;
		else if (xpos != last_x)
			xpos += 50;
	}
	if (xpos < last_x)
	{
		ft_look_left(dt, ROT / 3);
		ft_look_left(dt, ROT / 3);
		last_x = xpos;
	}
	else if (xpos > last_x)
	{
		ft_look_right(dt, ROT / 3);
		ft_look_right(dt, ROT / 3);
		last_x = xpos;
	}
}
