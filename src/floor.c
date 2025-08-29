/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:48:48 by erantala          #+#    #+#             */
/*   Updated: 2025/08/29 19:40:55 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	floor_calc(t_data *data, t_ray ray, int y);
void	floor_caster(t_data *data, t_ray ray, t_player player, int y)
{
	int	pos;
	float	z;
	// SET Y IN MULTICASTER
	ray.rayDirX[0] = player.pdx - player.planeX;
	ray.rayDirX[1] = player.pdx + player.planeX;
	ray.rayDirY[0] = player.pdy - player.planeY;
	ray.rayDirY[1] = player.pdy + player.planeY;
	z = 0.5 * HEIGHT;
	while (y < HEIGHT)
	{
		pos = y - HEIGHT / 2;
		ray.f_dist = z / pos;
		ray.F_StepX = ray.f_dist * (ray.rayDirX[1] - ray.rayDirX[0]) / WIDTH;
		ray.F_StepY = ray.f_dist * (ray.rayDirY[1] - ray.rayDirY[0]) / WIDTH;
		ray.floorX = player.pos[1] + ray.f_dist * ray.rayDirX[0];
		ray.floorY = player.pos[0] + ray.f_dist * ray.rayDirY[0];
		floor_calc(data, ray, y);
		y++;
	}
}

static	void	floor_calc(t_data *data, t_ray ray, int y)
{
	int				x;
	int				posX;
	int				posY;
	unsigned int	pixel[2];
	int				tex_pos;

	x = WIDTH - 1;
	while (x > 0)
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
		if (data->wall_full->pixels[(x + y) * 4] == 0)
		{
			mlx_put_pixel(data->wall_full, x, y, pixel[0]);
			mlx_put_pixel(data->wall_full, x, HEIGHT - y - 1, pixel[1]);
		}
		x--;
	}
}