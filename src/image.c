/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:17:09 by erantala          #+#    #+#             */
/*   Updated: 2025/08/22 00:13:52 by erantala         ###   ########.fr       */
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

void	render_frame(t_data	*data, t_player player, int x, int tex_x)
{
	int		y;
	int		step;
	double	pos;
	int		tex_y;
	unsigned int color;

	step = 1.0 * TXT / player.ray.height;
	pos = (player.ray.top - TXT / 2 + player.ray.height / 2) * step;
	y = player.ray.top;
	tex_x = abs(tex_x);
	while (y < player.ray.bottom)
	{
		if(tex_x > 128)
			write(1, "ERR\n", 4);
		tex_y = (int)pos & (TXT - 1);
		tex_y = abs(tex_y);
		pos += step;
		color = get_color(data->wall_txt[0], (tex_y * TXT + tex_x) * 4);	
		mlx_put_pixel(data->wall_full, x, y, color);
		y++;
	}
	(void)tex_y;
}
