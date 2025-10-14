/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:16:48 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 13:04:05 by erantala         ###   ########.fr       */
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
	double	camera_x;

	x = 0;
	while (x < WIDTH)
	{
		player.map_pos[0] = (int)player.pos[0];
		player.map_pos[1] = (int)player.pos[1];
		camera_x = 2 * x / (double)WIDTH - 1;
		player.ray.ray_x = player.pdx + player.plane_x * camera_x;
		player.ray.ray_y = player.pdy + player.plane_y * camera_x;
		calc_ray(&player, x);
		x++;
	}
}

static void	calc_ray(t_player *player, int x)
{
	player->ray.delta_y = 0;
	if (player->ray.ray_x != 0)
		player->ray.delta_x = fabs(1 / player->ray.ray_x);
	else
		player->ray.delta_x = 0;
	if (player->ray.ray_y != 0)
		player->ray.delta_y = fabs(1 / player->ray.ray_y);
	else
		player->ray.delta_y = 0;
	calc_step(player, x);
}

static void	calc_step(t_player *pr, int x)
{
	if (pr->ray.ray_x < 0)
	{
		pr->ray.step_x = -1;
		pr->ray.side_x = (pr->pos[1] - pr->map_pos[1]) * pr->ray.delta_x;
	}
	else
	{
		pr->ray.step_x = 1;
		pr->ray.side_x = (pr->map_pos[1] + 1.0 - pr->pos[1]) * pr->ray.delta_x;
	}
	if (pr->ray.ray_y < 0)
	{
		pr->ray.step_y = -1;
		pr->ray.side_y = (pr->pos[0] - pr->map_pos[0]) * pr->ray.delta_y;
	}
	else
	{
		pr->ray.step_y = 1;
		pr->ray.side_y = (pr->map_pos[0] + 1.0 - pr->pos[0]) * pr->ray.delta_y;
	}
	dda(pr, x);
}

static void	dda(t_player *player, int x)
{
	t_data	*data;

	data = get_data();
	while (1)
	{
		if (player->ray.side_x < player->ray.side_y)
		{
			player->ray.side_x += player->ray.delta_x;
			player->map_pos[1] += player->ray.step_x;
			player->ray.side = 0;
		}
		else
		{
			player->ray.side_y += player->ray.delta_y;
			player->map_pos[0] += player->ray.step_y;
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
		pr->ray.distance = (pr->ray.side_x - pr->ray.delta_x);
	else
		pr->ray.distance = (pr->ray.side_y - pr->ray.delta_y);
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
		pr->ray.point = pr->pos[0] + pr->ray.distance * pr->ray.ray_y;
	else
		pr->ray.point = pr->pos[1] + pr->ray.distance * pr->ray.ray_x;
	pr->ray.point -= floor(pr->ray.point);
	if (pr->ray.side == 0 && pr->pos[1] > pr->map_pos[1])
		pr->ray.side = EA;
	else if (pr->ray.side == 0)
		pr->ray.side = WE;
	else if (pr->pos[0] < pr->map_pos[0])
		pr->ray.side = NO;
	render_frame(get_data(), *pr, x, dir);
}
