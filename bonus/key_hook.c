/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:02:15 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 15:01:21 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && keydata.modifier == MLX_SHIFT)
		ft_move_north(data, SPEED * 0.5);
	else if (keydata.key == MLX_KEY_S && keydata.modifier == MLX_SHIFT)
		ft_move_south(data, SPEED * 0.5);
	else if (keydata.key == MLX_KEY_A && keydata.modifier == MLX_SHIFT)
		ft_move_west(data, SPEED * 0.5);
	else if (keydata.key == MLX_KEY_D && keydata.modifier == MLX_SHIFT)
		ft_move_east(data, SPEED * 0.5);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->player.pitch += 50;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->player.pitch -= 50;
}
