/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:17:09 by erantala          #+#    #+#             */
/*   Updated: 2025/08/23 02:02:44 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static	unsigned int get_color(mlx_texture_t *txt, int index)
{
	unsigned int	red;
	unsigned int	blue;
	unsigned int	green;
	unsigned int	alpha;

	red = txt->pixels[index];
	green = txt->pixels[index + 1];
	blue = txt->pixels[index + 2];
	alpha = txt->pixels[index + 3];
	return (red << 24 | green << 16 | blue << 8 | alpha);
}
static void draw_roof(t_data *data, int high, int y, int x)
{
	if (y < high)
	{
			mlx_put_pixel(data->wall_full, x, y, data->r_c);
	}
}

static void	draw_floor(t_data	*data, int low, int y, int x)
{
	if (y > low)
			mlx_put_pixel(data->wall_full, x, y, data->f_c);
}

static void make_roof(t_data *data, t_player player, int x)
{
	static int	low = HEIGHT;
	static int	high = 0;
	int			y;

	y = 0;
	if (player.ray.top > high)
		high = player.ray.top;
	if (player.ray.bottom < low)
		low = player.ray.bottom;
	while (y < low)
	{
		draw_roof(data, high, y, x);
		y++;	
	}
	y = HEIGHT;
	while (y > high)
	{
		draw_floor(data, low, y, x);
		y--;
	}
}

void	render_frame(t_data	*data, t_player player, int x, int tex_x)
{
	int		y;
	double	step;
	double	pos;
	int		tex_y;
	unsigned int color;

	if (player.ray.side == 0 && player.pos[1] > player.map_pos[1])
		player.ray.side = EA;
	else if (player.ray.side == 0)
		player.ray.side = WE;
	else if (player.pos[0] < player.map_pos[0])
		player.ray.side = NO;
	make_roof(data, player, x);
	step = 1.0 * TXT / player.ray.height;
	pos = (player.ray.top - HEIGHT / 2 + player.ray.height / 2) * step;
	y = player.ray.top;
	while (y < player.ray.bottom)
	{
		tex_y = (int)pos & (TXT - 1);
		pos += step;
		color = get_color(data->wall_txt[player.ray.side], (tex_y * TXT + tex_x) * 4);
		mlx_put_pixel(data->wall_full, x, y, color);
		y++;
	}
}
