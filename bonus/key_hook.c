/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:02:15 by erantala          #+#    #+#             */
/*   Updated: 2025/09/02 15:09:32 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && keydata.modifier == MLX_SHIFT)
		ft_move_north(data, SPEED * 1.5);
	else if (keydata.key == MLX_KEY_W)
		ft_move_north(data, SPEED);
	else if (keydata.key == MLX_KEY_S && keydata.modifier == MLX_SHIFT)
		ft_move_south(data, SPEED * 1.5);
	else if (keydata.key == MLX_KEY_S)
		ft_move_south(data, SPEED);
	else if (keydata.key == MLX_KEY_A && keydata.modifier == MLX_SHIFT)
			ft_move_west(data, SPEED * 1.5);
	else if (keydata.key == MLX_KEY_A)
		ft_move_west(data, SPEED);
	else if (keydata.key == MLX_KEY_D && keydata.modifier == MLX_SHIFT)
		ft_move_east(data, SPEED * 1.5);
	else if (keydata.key == MLX_KEY_D)
		ft_move_east(data, SPEED);
}
