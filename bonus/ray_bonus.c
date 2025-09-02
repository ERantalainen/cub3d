/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 05:01:31 by erantala          #+#    #+#             */
/*   Updated: 2025/09/01 23:29:37 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static t_thr	*alloc_threads(t_thr *thr)
{
	thr = arena_malloc(sizeof(t_thr) * (COUNT * 2));
	return (thr);
}
time_t	get_time(void);

void	multi_caster(t_data	*data)
{
	static t_thr *thr = NULL;
	time_t				start;
	int			i;

	i = 0;
	if (!thr)
		thr = alloc_threads(thr);
	start = get_time();
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
	time_t end = get_time();
	printf("Start: %li End: %li Total: %li\n", start, end, end- start);
}
