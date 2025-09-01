/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:09:31 by erantala          #+#    #+#             */
/*   Updated: 2025/09/01 17:29:44 by erantala         ###   ########.fr       */
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

void	render_frame(t_thr *thread, t_player pr, int x, int dir)
{
	int		y;
	double	step;
	double	pos;
	int		tex_y;
	t_data	*data;

	data = get_data();
	pr.ray.txt_size = data->wall_txt[pr.ray.side]->height;
	pr.ray.tex_x = (int)(pr.ray.point *  pr.ray.txt_size);
	if (dir == 0 && pr.ray.rayX > 0)
		pr.ray.tex_x =  pr.ray.txt_size - pr.ray.tex_x - 1;
	if (dir == 1 && pr.ray.rayY > 0)
		pr.ray.tex_x =  pr.ray.txt_size - pr.ray.tex_x - 1;
	step = 1.0 * pr.ray.txt_size / pr.ray.height;
	pos = (pr.ray.top - HEIGHT / 2 + pr.ray.height / 2) * step;
	y = pr.ray.top;
	while (y < pr.ray.bottom)
	{
		tex_y = (int)pos & ( pr.ray.txt_size - 1);
		pos += step;
		thread->temps[y][x - (SLICE * thread->n)] = get_color(data->wall_txt[pr.ray.side], (tex_y *  pr.ray.txt_size + pr.ray.tex_x) * 4);
		y++;
	}
}

void	combine(t_data	*data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (data->wabuffer[y][x] != 0)
				mlx_put_pixel(data->wall_full, x, y, data->wabuffer[y][x]);
			if (data->wall_full->pixels[(y * WIDTH + x) * 4] == 0)
				mlx_put_pixel(data->wall_full, x, y, data->buffer[y][x]);
			x++;
		}
		y++;
	}
}

void	*ray_call(void *param)
{
	t_thr	*thread;
	int		max;
	int		start;

	thread = (t_thr *)param;
	max = (thread->n + 1) * SLICE;
	start = thread->n * SLICE;
	RayCaster(thread->data->player, thread, start, max);
	return (NULL);
}