/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:59:56 by erantala          #+#    #+#             */
/*   Updated: 2025/08/19 16:58:56 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	ft_look_right(t_data *data)
{
	data->player.dir[0] += -0.1;
	if (data->player.dir[0] < 0)
		data->player.dir[0] += 2 * PI;
	data->player.pdx = (cos(data->player.dir[0]));
	data->player.pdy = (sin(data->player.dir[0]));
}

void	ft_look_left(t_data *data)
{

}


