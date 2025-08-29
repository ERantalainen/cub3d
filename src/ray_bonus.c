/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:16:40 by erantala          #+#    #+#             */
/*   Updated: 2025/08/29 19:38:54 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <pthread.h>
void	*multi_floor(void	*param);
void	multi_caster(t_data	*data)
{
	pthread_t	floor;

	floor = 0;
	ft_memset(data->wall_full->pixels, 0, WIDTH * HEIGHT * 4);
	if (pthread_create(&floor, NULL, multi_floor, data) != 0)
		ft_exit("Error creating threads", 1);
	RayCaster(data->player);

}

void	*multi_floor(void	*param)
{
	t_data	*data;

	data = (t_data *)param;
	floor_caster(data, data->player.ray, data->player);
	write(1, "here\n", 5);
	return (NULL);
}