/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:16:48 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 15:12:00 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	calc_ray(t_player *player, int x);
static void	calc_step(t_player *pr, int x);
static void	dda(t_player *player, int x);
static void	wall_dist(t_player *player, int dir, int x);

void	raycaster(t_player player)
{
	int		x;
	double	cameraX;

	x = 0;
	while (x < WIDTH)
	{
		player.map_pos[0] = (int)player.pos[0];
		player.map_pos[1] = (int)player.pos[1];
		cameraX = 2 * x / (double)WIDTH - 1;
		player.ray.rayX = player.pdx + player.planeX * cameraX;
		player.ray.rayY = player.pdy + player.planeY * cameraX;
		calc_ray(&player, x);
		x++;
	}
}

static void	calc_ray(t_player *player, int x)
{
	player->ray.deltaY = 0;
	if (player->ray.rayX != 0)
		player->ray.deltaX = fabs(1 / player->ray.rayX);
	else
		player->ray.deltaX = 0;
	if (player->ray.rayY != 0)
		player->ray.deltaY = fabs(1 / player->ray.rayY);
	else
		player->ray.deltaY = 0;
	calc_step(player, x);
}

static void	calc_step(t_player *pr, int x)
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
	if (pr->ray.rayY < 0)
	{
		pr->ray.stepY = -1;
		pr->ray.sideY = (pr->pos[0] - pr->map_pos[0]) * pr->ray.deltaY;
	}
	else
	{
		pr->ray.stepY = 1;
		pr->ray.sideY = (pr->map_pos[0] + 1.0 - pr->pos[0]) * pr->ray.deltaY;
	}
	dda(pr, x);
}

static void	dda(t_player *player, int x)
{
	t_data	*data;

	data = get_data();
	while (1)
	{
		if (player->ray.sideX < player->ray.sideY)
		{
			player->ray.sideX += player->ray.deltaX;
			player->map_pos[1] += player->ray.stepX;
			player->ray.side = 0;
		}
		else
		{
			player->ray.sideY += player->ray.deltaY;
			player->map_pos[0] += player->ray.stepY;
			player->ray.side = 1;
		}
		if (data->map[player->map_pos[0]][player->map_pos[1]] == '1')
			break ;
	}
	wall_dist(player, player->ray.side, x);
}

static void	wall_dist(t_player *pr, int dir, int x)
{
	if (dir == 0)
		pr->ray.distance = (pr->ray.sideX - pr->ray.deltaX);
	else
		pr->ray.distance = (pr->ray.sideY - pr->ray.deltaY);
	if (pr->ray.distance == 0)
		pr->ray.distance = 1;
	pr->ray.height = (int)(HEIGHT / pr->ray.distance);
	pr->ray.top = -pr->ray.height / 2 + HEIGHT / 2;
	if (pr->ray.top < 0)
		pr->ray.top = 0;
	pr->ray.bottom = pr->ray.height / 2 + HEIGHT / 2;
	if (pr->ray.bottom > HEIGHT)
		pr->ray.bottom = HEIGHT;
	if (dir == 0)
		pr->ray.point = pr->pos[0] + pr->ray.distance * pr->ray.rayY;
	else
		pr->ray.point = pr->pos[1] + pr->ray.distance * pr->ray.rayX;
	pr->ray.point -= floor(pr->ray.point);
	if (pr->ray.side == 0 && pr->pos[1] > pr->map_pos[1])
		pr->ray.side = EA;
	else if (pr->ray.side == 0)
		pr->ray.side = WE;
	else if (pr->pos[0] < pr->map_pos[0])
		pr->ray.side = NO;
	render_frame(get_data(), *pr, x, dir);
}
