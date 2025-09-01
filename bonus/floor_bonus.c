/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:48:48 by erantala          #+#    #+#             */
/*   Updated: 2025/09/01 18:44:35 by erantala         ###   ########.fr       */
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
	start = thread->n * SLICE;
	max = (thread->n + 1) * SLICE;
	thread->max = max;
	floor_caster(data, data->player.ray, start, thread);
	return (NULL);
}

static void	floor_calc(int x, t_ray ray, int y, t_thr *thr);
void	*floor_caster(t_data *data, t_ray ray, int x, t_thr *thr)
{
	int	pos;
	float	z;
	int	y;

	y = HEIGHT / 2 + 1;
	ray.rayDirX[0] = data->player.pdx - data->player.planeX;
	ray.rayDirX[1] = data->player.pdx + data->player.planeX;
	ray.rayDirY[0] = data->player.pdy - data->player.planeY;
	ray.rayDirY[1] = data->player.pdy + data->player.planeY;
	z = 0.5 * HEIGHT;
	while (y < HEIGHT)
	{
		pos = y - HEIGHT / 2;
		ray.f_dist = z / pos;
		ray.F_StepX = ray.f_dist * (ray.rayDirX[1] - ray.rayDirX[0]) / WIDTH;
		ray.F_StepY = ray.f_dist * (ray.rayDirY[1] - ray.rayDirY[0]) / WIDTH;
		ray.floorX = data->player.pos[1] + ray.f_dist * ray.rayDirX[0];
		ray.floorY = data->player.pos[0] + ray.f_dist * ray.rayDirY[0];
		floor_calc(x, ray, y, thr);
		y++;
	}
	return (NULL);
}

static	void	floor_calc(int x, t_ray ray, int y, t_thr *thr)
{
	int				posX;
	int				posY;
	unsigned int	pixel[2];
	int				tex_pos;
	t_data 			*data;

	data = get_data();
	while (x < thr->max)
	{
		posX = (int)(ray.floorX);
		posY = (int)(ray.floorY);
		ray.floorTX = (int)(data->floor_txt->width * (ray.floorX - posX)) & (data->floor_txt->width - 1) ;
		ray.floorTY = (int)(data->floor_txt->height * (ray.floorY - posY)) & (data->floor_txt->height - 1) ;
		ray.floorX += ray.F_StepX;
		ray.floorY += ray.F_StepY;
		tex_pos = (data->floor_txt->width * ray.floorTY + ray.floorTX) * 4;
		pixel[0] = get_color(data->floor_txt, tex_pos);
		pixel[1] = get_color(data->ceil_txt, tex_pos);
		thr->temps[y][x - thr->n * SLICE] = pixel[0];
		thr->temps[HEIGHT - y - 1][x - thr->n * SLICE] = pixel[1];
		x++;
	}
}