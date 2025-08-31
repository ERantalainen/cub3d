/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 05:01:31 by erantala          #+#    #+#             */
/*   Updated: 2025/08/31 05:17:38 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

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
			if (data->wall_full->pixels[(y * WIDTH + x) * 4] == 0)
				mlx_put_pixel(data->wall_full, x, y, data->buffer[y][x]);
			x++;
		}
		y++;
	}
}

static void	*floor_call(void	*param)
{
	t_data	*data;
	int		y;

	y = 0;
	data = (t_data *)param;
	while (y < HEIGHT)
	{
		ft_memset(data->buffer[y], 0, WIDTH * sizeof(unsigned int));
		y++;
	}
	floor_caster(data, data->player.ray, data->player);
	return (NULL);
}

void	multi_caster(t_data	*data)
{
	pthread_t	floor;

	ft_memset(data->wall_full->pixels, 0, (WIDTH * HEIGHT) * 4);
	if (pthread_create(&floor, NULL, floor_call, (void *)data) != 0)
		ft_exit("Error creating thread\n", 1);
	RayCaster(data->player);
	pthread_join(floor, NULL);
	combine(data);
}