/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:24:04 by erantala          #+#    #+#             */
/*   Updated: 2025/08/18 18:23:38 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	game_hook(void *param);

void	start_game(t_data *data)
{
	mlx_close_hook(data->mlx, ft_close, NULL);
	mlx_loop_hook(data->mlx, game_hook, data);
}

void	draw_game(t_data	*data)
{

}

void	game_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_exit("", 1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_move_north(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_move_south(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_move_west(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_move_east(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_look_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_look_right(data);
	draw_game(data);
}
