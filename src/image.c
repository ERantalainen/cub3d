/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:17:09 by erantala          #+#    #+#             */
/*   Updated: 2025/08/21 18:41:03 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	render_frame(t_data	*data, t_player player, int x)
{
	int		y;
	int		step;
	double	pos;
	int		tex_y;

	int color = (255 << 24 | 6 << 16 | 135 << 8 | 255);
	printf("%f %f %f %f %d\n", player.ray.deltaX, player.ray.deltaY, player.ray.distance, player.ray.rayX, player.ray.height);
	if (player.ray.height == 0)
		player.ray.height = 1;
	step = TXT / player.ray.height;
	pos = (player.ray.bottom - TXT / 2 + player.ray.height / 2) * step;
	y = player.ray.bottom;
	while (y < HEIGHT)
	{
		tex_y = (int)pos;
		pos += step;
		mlx_put_pixel(data->wall_full, x, y, color);
		y++;
	}
}
