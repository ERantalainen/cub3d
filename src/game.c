/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:24:04 by erantala          #+#    #+#             */
/*   Updated: 2025/08/22 15:55:18 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	game_hook(void *param);

void	start_game(t_data *data)
{
	mlx_close_hook(data->mlx, ft_close, NULL);
	mlx_loop_hook(data->mlx, game_hook, data);
	puts("here start");
	mlx_image_to_window(data->mlx, data->player.mm, data->player.map_pos[1], data->player.map_pos[0]);
	mlx_set_instance_depth(data->player.mm->instances, 4);
	mlx_loop(data->mlx);
}

void	draw_game(t_data	*data)
{
	static double	posY = 0.0;
	static double	posX = 0.0;
	static double	dirX = 0.0;
	static double	dirY = 0.0;

	if ((data->player.pos[0] != posY || data->player.pos[1] != posX)
		|| data->player.dir[1] != dirY || data->player.dir[0] != dirX)
	{
		RayCaster(data->player);
		render_minimap(data);
		data->player.mm->instances->x = ceil(data->player.pos[1]) * 10;
		data->player.mm->instances->y = ceil(data->player.pos[0]) * 10;
		posY = data->player.pos[0];
		posX = data->player.pos[1];
		dirX = data->player.dir[0];
		dirY = data->player.dir[1];
	}
	else
		return ;
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
