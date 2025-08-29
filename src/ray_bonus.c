/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:16:40 by erantala          #+#    #+#             */
/*   Updated: 2025/08/30 01:58:35 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"
#include <pthread.h>
void	*multi_floor(void	*param);

static void	combine(t_data	*data);
void	*multi_ray(void *param);
void	multi_caster(t_data	*data)
{
	pthread_t		floor;
	pthread_t		cast1;
	pthread_t		cast2;
	unsigned int	buffer[2][WIDTH][HEIGHT];
	
	floor = 0;
	ft_memset(data->wall_full->pixels, 0, WIDTH * HEIGHT * 4);
	if (pthread_create(&floor, NULL, multi_floor, data) != 0)
		ft_exit("Error creating threads", 1);
	data->multi_x = 0;
	if (pthread_create(&cast1, NULL, multi_ray, data) != 0)
		ft_exit("Error creating threads", 1);
	data->multi_x = 1;
	if (pthread_create(&cast2, NULL, multi_ray, data) != 0)
		ft_exit("Error creating threads", 1);
	pthread_join(floor, &data->buffer);
	pthread_join(cast1, &buffer[0]);
	pthread_join(cast2, &buffer[1]);
	ft_memcpy(data->wabuffer, buffer[0], HEIGHT * (WIDTH / 2));
	ft_memcpy(data->wabuffer + HEIGHT * (WIDTH / 2), buffer[1], HEIGHT * WIDTH / 2);
	combine(data);
}

static void	combine(t_data	*data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(data->wall_full, x, y, data->wabuffer[y][x]);
			if (data->wall_full->pixels[(y * WIDTH + x) * 4] == 0)
				mlx_put_pixel(data->wall_full, x, y, data->buffer[y][x]);
			x++;
		}
		y++;
	}
}
void	*multi_ray(void *param)
{
	t_data	*data;

	data = param;
	if (data->multi_x == 0)
		RayCaster(data->player, WIDTH / 2, 0);
	else
		RayCaster(data->player, WIDTH, WIDTH / 2);
	return (NULL);
}
void	*multi_floor(void	*param)
{
	t_data	*data;
	data = (t_data *)param;
	floor_caster(data, data->player.ray, data->player);
	return ((void *)data->buffer);
}