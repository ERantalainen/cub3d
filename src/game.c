/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:24:04 by erantala          #+#    #+#             */
/*   Updated: 2025/08/31 02:02:48 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	game_hook(void *param);

void	start_game(t_data *data)
{
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_close_hook(data->mlx, ft_close, NULL);
	mlx_loop_hook(data->mlx, game_hook, data);
	mlx_cursor_hook(data->mlx, cursor_pos, data);
	puts("here start");
	RayCaster(data->player);
	floor_caster(data, data->player.ray, data->player);
	mlx_image_to_window(data->mlx, data->wall_full, 0, 0);
	render_minimap(data);
	mlx_image_to_window(data->mlx, data->player.mm, ceil(data->player.pos[1]), round((data->player.pos[0])));
	mlx_set_instance_depth(data->player.mm->instances, 2);
	mlx_loop(data->mlx);
}

static void	compass(t_data *data)
{
	static mlx_image_t	*string = NULL;
	static mlx_image_t	*fp_txt = NULL;
	char				*dir;
	int					fps;
	char				*fp;

	fps = round(1 / data->mlx->delta_time);
	if (string || fp_txt)
	{
		mlx_delete_image(data->mlx, string);
		mlx_delete_image(data->mlx, fp_txt);
		fp_txt = NULL;
		string = NULL;
	}
	dir = ft_itoa(data->player.dir[0] * (180 / PI));
	fp = ft_itoa(fps);
	string = mlx_put_string(data->mlx, dir, WIDTH / 2 - 10, 50);
	fp_txt = mlx_put_string(data->mlx, ft_stradd("FPS:", fp), WIDTH - 75, 15);
	mlx_set_instance_depth(fp_txt->instances, 50);
	free(dir);
	free(fp);
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
		ft_memset(data->wall_full->pixels, 0, WIDTH * HEIGHT * 4);
		RayCaster(data->player);
		compass(data);
		data->player.mm->instances->x = floor(data->player.pos[1]) * 10;
		data->player.mm->instances->y = floor(data->player.pos[0]) * 10;
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_look_left(data, ROT);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_look_right(data, ROT);
	 draw_game(data);
}
