/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:09:31 by erantala          #+#    #+#             */
/*   Updated: 2025/08/31 05:01:00 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

unsigned int get_color(mlx_texture_t *txt, int index)
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

void	render_frame(t_data	*data, t_player player, int x, int dir)
{
	int		y;
	double	step;
	double	pos;
	int		tex_y;
	unsigned int color;

	player.ray.txt_size = data->wall_txt[player.ray.side]->height;
	player.ray.tex_x = (int)(player.ray.point *  player.ray.txt_size);
	if (dir == 0 && player.ray.rayX > 0)
		player.ray.tex_x =  player.ray.txt_size - player.ray.tex_x - 1;
	if (dir == 1 && player.ray.rayY > 0)
		player.ray.tex_x =  player.ray.txt_size - player.ray.tex_x - 1;
	step = 1.0 * player.ray.txt_size / player.ray.height;
	pos = (player.ray.top - HEIGHT / 2 + player.ray.height / 2) * step;
	y = player.ray.top;
	while (y < player.ray.bottom)
	{
		tex_y = (int)pos & ( player.ray.txt_size - 1);
		pos += step;
		color = get_color(data->wall_txt[player.ray.side], (tex_y *  player.ray.txt_size + player.ray.tex_x) * 4);
		mlx_put_pixel(data->wall_full, x, y, color);
		y++;
	}
}
