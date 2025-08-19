/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:58:59 by erantala          #+#    #+#             */
/*   Updated: 2025/08/19 17:27:38 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	RayCaster(t_player player)
{
	int		x;
	double	cameraX;
	double	rayX;
	double	rayY;

	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * x / (double)WIDTH - 1;
		player.ray.rayX = player.dir[0] + 0.66 * cameraX;
		player.ray.rayY = player.dir[1] + 0.66 * cameraX;
	}
	calc_ray(&player);

}

static	void calc_ray(t_player *player)
{
	if (player->ray.rayX != 0)
		player->ray.deltaX = fabs(1 / player->ray.rayX);
	else
		player->ray.deltaX = 0;
	if (player->ray.rayY != 0)
		player->ray.deltaY = fabs(1 / player->ray.rayY);
	calc_step(player);
}

static	void	calc_step(t_player *pr)
{
	if (pr->ray.rayX < 0)
	{
		pr->ray.stepX = -1;
		pr->ray.sideX = (pr->pos[1] - pr->map_pos[1]) * pr->ray.deltaX;
	}
	else
	{
		pr->ray.stepX = 1;
		pr->ray.sideX = (pr->map_pos[1] + 1.0 - pr->pos[1]) * pr->ray.deltaX;
	}
	if (pr->ray.rayX < 0)
	{
		pr->ray.stepY = -1;
		pr->ray.sideY = (pr->pos[0] - pr->map_pos[0]) * pr->ray.deltaY;
	}
	else
	{
		pr->ray.stepY = 1;
		pr->ray.sideY = (pr->map_pos[0] + 1.0 - pr->pos[1]) * pr->ray.deltaX;
	}
	dda(pr);
}

static void	dda(t_player *player)
{
	int	dir;
	t_data	*data;

	data = get_data();
	while (1)
	{
		if (player->ray.sideX < player->ray.sideY)
		{
			player->ray.sideX += player->ray.deltaX;
			player->map_pos[1] += player->ray.stepX;
			dir = 0;
		}
		else
		{
			player->ray.sideY += player->ray.deltaX;
			player->map_pos[0] += player->ray.stepY;
			dir = 1;
		}
		if ((data->map[player->map_pos[0]][player->map_pos[1]])
			&& (data->map[player->map_pos[0]][player->map_pos[1]] == '1'))
			break ;
	}
	wall_dist(player, dir);
}

static void	wall_dist(t_player *player, int dir)
{
	if (dir == 0)
		player->ray.distance = (player->ray.sideX - player->ray.deltaX);
	else
		player->ray.distance = (player->ray.sideY - player->ray.deltaY);
	player->ray.height = (int)(HEIGHT / player->ray.distance);
	player->ray.bottom = player->ray.height / 2 + HEIGHT / 2;
	if (player->ray.bottom < 0)
		player->ray.bottom = 0;
	player->ray.top = player->ray.height / 2 + HEIGHT / 2;
	if (player->ray.top > HEIGHT)
		player->ray.top = HEIGHT - 1;
}