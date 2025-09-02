/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:44:31 by erantala          #+#    #+#             */
/*   Updated: 2025/09/02 16:15:03 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	sort_sprite(t_data *data, t_player pr)
{
	int	i;
	double	x_pos;
	double	y_pos;

	i = 0;
	while (i < SPCOUNT)
	{
		data->sps->order[i] = i;
		x_pos = (pr.pdx - data->sps->sp[i].x) * (pr.pdx - data->sps->sp[i].x);
		y_pos = (pr.pdy - data->sps->sp[i].y) * (pr.pdy - data->sps->sp[i].y);
		data->sps->sp_dist[i] = x_pos + y_pos;
		i++;
	}
	i = 0;
	while (i < SPCOUNT - 1)
	{
		if (data->sps->sp_dist[i] > data->sps->sp_dist[i + 1])
		{
			data->sps->sp_dist[i];
		}
	}
}