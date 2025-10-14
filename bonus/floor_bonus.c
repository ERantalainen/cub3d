/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:48:48 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 13:04:56 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	*flr_mlt(void *param)
{
	t_thr	*thread;
	t_data	*data;
	int		max;
	int		start;
	t_ray	ray;

	data = get_data();
	thread = (t_thr *)param;
	ray = data->player.ray;
	start = thread->n * VSLICE;
	if (thread->n == 0)
		start += 1;
	max = (VSLICE * (thread->n + 1));
	thread->max = max;
	ray.ray_dirx[0] = data->player.pdx - data->player.plane_x;
	ray.ray_dirx[1] = data->player.pdx + data->player.plane_x;
	ray.ray_diry[0] = data->player.pdy - data->player.plane_y;
	ray.ray_diry[1] = data->player.pdy + data->player.plane_y;
	floor_caster(data, ray, start, thread);
	return (NULL);
}

static void	floor_calc(t_data *data, t_ray ray, int y, bool floor);

void	*floor_caster(t_data *data, t_ray ray, int y, t_thr *thr)
{
	int		pos;
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
		ray.f_stepx = ray.f_dist * (ray.ray_dirx[1] - ray.ray_dirx[0]) / WIDTH;
		ray.f_stepy = ray.f_dist * (ray.ray_diry[1] - ray.ray_diry[0]) / WIDTH;
		ray.floor_x = data->player.pos[1] + ray.f_dist * ray.ray_dirx[0];
		ray.floor_y = data->player.pos[0] + ray.f_dist * ray.ray_diry[0];
		floor_calc(data, ray, y, floor);
		y++;
	}
	return (NULL);
}

static void	floor_calc(t_data *data, t_ray ray, int y, bool flr)
{
	int				pos_x;
	int				pos_y;
	unsigned int	pixel[2];
	int				tex_pos;
	int				x;

	x = -1;
	while (++x < WIDTH)
	{
		pos_x = (int)(ray.floor_x);
		pos_y = (int)(ray.floor_y);
		ray.floor_tx = (int)(data->flr_txt->width * (ray.floor_x
					- pos_x)) & (data->flr_txt->width - 1);
		ray.floor_ty = (int)(data->flr_txt->height * (ray.floor_y
					- pos_y)) & (data->flr_txt->height - 1);
		ray.floor_x += ray.f_stepx;
		ray.floor_y += ray.f_stepy;
		tex_pos = (data->flr_txt->width * ray.floor_ty + ray.floor_tx) * 4;
		pixel[0] = get_color(data->flr_txt, tex_pos);
		pixel[1] = get_color(data->ceil_txt, tex_pos);
		if (!flr)
			place_pixel(data->floor, pixel[1], x, y);
		else
			place_pixel(data->floor, pixel[0], x, y);
	}
}
