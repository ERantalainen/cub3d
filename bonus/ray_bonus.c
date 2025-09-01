/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 05:01:31 by erantala          #+#    #+#             */
/*   Updated: 2025/09/01 18:39:24 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	combine_wall(t_data *data, t_thr *thr)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < COUNT)
	{
		y = 0;
		while (y < HEIGHT)
		{
			x = 0;
			while (x < SLICE)
			{
				data->wabuffer[y][x + (thr[i].n * SLICE)] = thr[i].temps[y][x];
				x++;
			}
			y++;
		}
		i++;
	}
}

static void	combine_floor(t_data	*data, t_thr *thr)
{
	int	i;
	int	y;
	int	x;

	i = COUNT;
	while (i < COUNT * 2)
	{
		y = 0;
		while (y < HEIGHT)
		{
			x = 0;
			while (x < SLICE)
			{
				data->buffer[y][x + (thr[i].n * SLICE)] = thr[i].temps[y][x];
				x++;
			}
			y++;
		}
		i++;
	}
}

static t_thr	*alloc_threads(t_thr *thr)
{
	int	i;
	int	y;

	i = 0;
	thr = arena_malloc(sizeof(t_thr) * (COUNT * 2));
	while (i < COUNT * 2)
	{
		y = 0;
		thr[i].temps = arena_malloc(sizeof(unsigned int *) * HEIGHT);
		while (y < HEIGHT)
		{
			thr[i].temps[y] = arena_malloc(sizeof(unsigned int) * SLICE);
			y++;
		}
		i++;
	}
	return (thr);
}

static void	clear_threads(t_thr *thr)
{
	int	i;
	int	y;

	i = 0;
	while (i < COUNT * 2)
	{
		y = 0;
		while (y < HEIGHT)
		{
			thr[i].temps[y] = ft_memset(thr[i].temps[y], 0, SLICE * sizeof(unsigned int));
			y++;
		}
		i++;
	}
}

void	multi_caster(t_data	*data)
{
	static t_thr *thr = NULL;
	int			i;

	i = 0;
	if (!thr)
		thr = alloc_threads(thr);
	else
		clear_threads(thr);
	while (i < COUNT)
	{
		thr[i].n = i;
		thr[i + COUNT].n = i;
		thr[i].data = get_data();
		if (pthread_create(&thr[i].id, NULL, ray_call, &thr[i]) != 0)
			ft_exit("Error creating thread\n", 1);
		if (pthread_create(&thr[i + COUNT].id, NULL, flr_mlt, &thr[i + COUNT]))
			ft_exit("Error creating threads\n", 1);
		i++;
	}
	i = 0;
	while (i < COUNT * 2)
		pthread_join(thr[i++].id, NULL);
	combine_wall(data, thr);
	combine_floor(data, thr);
	combine(data);
}
