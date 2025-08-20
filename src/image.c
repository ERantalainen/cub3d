/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:17:09 by erantala          #+#    #+#             */
/*   Updated: 2025/08/20 17:40:23 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	render_frame(t_data	*data, t_player player, int x)
{
		mlx_image_to_window(data->mlx, data->wall_img[1], x, player.ray.bottom);
}
