/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:48:48 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 17:45:10 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	*flr_mlt(void	*param)
{
	t_thr	*thread;
	t_data	*data;
	int		max;
	int		start;

	data = get_data();
	thread = (t_thr *)param;
	start = thread->n * VSLICE;
	if (thread->n == 0)
		start += 1;
	max = (VSLICE * (thread->n + 1));
	thread->max = max;
	data->player.ray.rayDirX[0] = data->player.pdx - data->player.planeX;
	data->player.ray.rayDirX[1] = data->player.pdx + data->player.planeX;
	data->player.ray.rayDirY[0] = data->player.pdy - data->player.planeY;
	data->player.ray.rayDirY[1] = data->player.pdy + data->player.planeY;
	floor_caster(data, data->player.ray, start, thread);
	return (NULL);
}

static void	floor_calc(t_data *data, t_ray ray, int y, bool floor);
void	*floor_caster(t_data *data, t_ray ray, int y, t_thr *thr)
{
	int	pos;
	float	z;
	bool	floor;

	z = (0.5 * HEIGHT);
	while (y < thr->max)
	{
		floor = y > HEIGHT / 2 + data->player.pitch;
		if (floor)
			pos = (y - (HEIGHT / 2) - data->player.pitch);
		else
			pos = (HEIGHT / 2) - y + data->player.pitch;
		ray.f_dist = z / pos;
		ray.F_StepX = ray.f_dist * (ray.rayDirX[1] - ray.rayDirX[0]) / WIDTH;
		ray.F_StepY = ray.f_dist * (ray.rayDirY[1] - ray.rayDirY[0]) / WIDTH;
		ray.floorX = data->player.pos[1] + ray.f_dist * ray.rayDirX[0];
		ray.floorY = data->player.pos[0] + ray.f_dist * ray.rayDirY[0];
		floor_calc(data, ray, y, floor);
		y++;
	}
	return (NULL);
}

static	void	floor_calc(t_data *data, t_ray ray, int y, bool flr)
{
	int				posX;
	int				posY;
	unsigned int	pixel[2];
	int				tex_pos;
	int				x;

	x = 0;
	while (x < WIDTH)
	{
		posX = (int)(ray.floorX);
		posY = (int)(ray.floorY);
		ray.floorTX = (int)(data->flr_txt->width * (ray.floorX - posX)) & (data->flr_txt->width - 1);
		ray.floorTY = (int)(data->flr_txt->height * (ray.floorY - posY)) & (data->flr_txt->height - 1);
		ray.floorX += ray.F_StepX;
		ray.floorY += ray.F_StepY;
		tex_pos = (data->flr_txt->width * ray.floorTY + ray.floorTX) * 4;
		pixel[0] = get_color(data->flr_txt, tex_pos);
		pixel[1] = get_color(data->ceil_txt, tex_pos);
		if (!flr)
			place_pixel(data->floor, pixel[1], x, y);
		else
			place_pixel(data->floor, pixel[0], x, y);
		x++;
	}
}