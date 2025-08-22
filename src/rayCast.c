/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:58:59 by erantala          #+#    #+#             */
/*   Updated: 2025/08/22 03:40:44 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void calc_ray(t_player *player, int x);
static void	calc_step(t_player *pr, int x);
static void	dda(t_player *player, int x);
static void	wall_dist(t_player *player, int dir, int x);

void	RayCaster(t_player player)
{
	int		x;
	double	cameraX;
	t_data	*data;

	data = get_data();
	x = 0;
	mlx_delete_image(data->mlx, data->wall_full);
	data->wall_full = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	printf("%f %f\n", player.pdx, player.pdy);
	while (x < WIDTH)
	{
		cameraX = 2 * x / (double)WIDTH - 1;
		player.ray.rayX = player.pdx + player.planeX * cameraX;
		player.ray.rayY = player.pdy + player.planeY * cameraX;
		player.map_pos[0] = (int)player.pos[0];
		player.map_pos[1] = (int)player.pos[1];
		calc_ray(&player, x);
		x++;
	}
	mlx_image_to_window(data->mlx, data->wall_full, 0, 0);
	mlx_set_instance_depth(data->wall_full->instances, 0);
}

static	void calc_ray(t_player *player, int x)
{
	player->ray.deltaY = 0;
	if (player->ray.rayX != 0)
		player->ray.deltaX = fabs(1 / player->ray.rayX);
	else
		player->ray.deltaX = 0;
	if (player->ray.rayY != 0)
		player->ray.deltaY = fabs(1 / player->ray.rayY);
	calc_step(player, x);
}

static	void	calc_step(t_player *pr, int x)
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
		pr->ray.sideY = (pr->map_pos[0] + 1.0 - pr->pos[1]) * pr->ray.deltaY;
	}
	dda(pr, x);
}

static void	dda(t_player *player, int x)
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
			player->ray.sideY += player->ray.deltaY;
			player->map_pos[0] += player->ray.stepY;
			dir = 1;
		}
		if ((player->map_pos[0] < 0 || player->map_pos[0] >= data->map_h)
		||	player->map_pos[1] < 0 || player->map_pos[1] >= data->map_w)
			break ;
		if  (data->map[player->map_pos[0]][player->map_pos[1]] == '1')
			break ;
	}
	wall_dist(player, dir, x);
}

static void	wall_dist(t_player *pr, int dir, int x)
{
	if (dir == 0)
		pr->ray.distance = (pr->ray.sideX - pr->ray.deltaX);
	else
		pr->ray.distance = (pr->ray.sideY - pr->ray.deltaY);
	pr->ray.height = (int)(HEIGHT / pr->ray.distance);
	printf("%f\n", pr->ray.distance);
	pr->ray.top = -pr->ray.height / 2 + HEIGHT / 2;
	if (pr->ray.top < 0)
		pr->ray.top = 0;
	pr->ray.bottom = pr->ray.height / 2 + HEIGHT / 2;
	if (pr->ray.bottom < 0)
		pr->ray.bottom = 0;
	if (dir == 0)
		pr->ray.point = pr->pos[0] + pr->ray.distance * pr->ray.rayY;
	else
		pr->ray.point = pr->pos[1] + pr->ray.distance * pr->ray.rayX;
	pr->ray.point -= floor(pr->ray.point);
	
	pr->ray.tex_x = (int)(pr->ray.point * TXT);
	if (dir == 0 && pr->ray.rayX > 0)
		pr->ray.tex_x = TXT - pr->ray.tex_x - 1;
	if (dir == 1 && pr->ray.rayY > 0)
		pr->ray.tex_x = TXT - pr->ray.tex_x - 1;
	render_frame(get_data(), *pr, x, pr->ray.tex_x);
}
