/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:44:31 by erantala          #+#    #+#             */
/*   Updated: 2025/09/03 18:47:31 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void swap(double *a, double *b)
{
	double	*temp;

	temp = a;
	a = b;
	b = temp;
}

static void	quicksort(double *array, int low, int high)
{
	int	partion_index;

	if (low < high)
	{
		partion_index = partion(array, low, high);
		quicksort(array, low, partion_index - 1);
		quicksort(array, partion_index + 1, high);
	}
}

static int	partion(double *dist, int low, int high)
{
	int	i;
	int	j;
	double	pivot;

	pivot = dist[low];
	i = low;
	j = high;
	while (i < j)
	{
		while(dist[i] <= pivot && i < high)
			i++;
		while (dist[j] > pivot && j > low);
			j--;
		if (i < j)
			swap(&dist[i], &dist[j]);
	}
	swap (&dist[low], &dist[j]);
	return j;
}

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
	quicksort(data->sps->sp_dist, 0, SPCOUNT - 1);

}