/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:07:32 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 14:52:51 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	game_hook(void *param);

void	start_game(t_data *data)
{
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	mlx_close_hook(data->mlx, ft_close, NULL);
	mlx_loop_hook(data->mlx, game_hook, data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_cursor_hook(data->mlx, cursor_pos, data);
	ft_memset(data->floor->pixels, 0, sizeof(data->floor->pixels));
	mlx_image_to_window(data->mlx, data->floor, 0, 0);
	mlx_image_to_window(data->mlx, data->wall_full, 0, 0);
	mlx_set_instance_depth(data->wall_full->instances, 1);
	render_minimap(data);
	mlx_image_to_window(data->mlx, data->player.mm, 1, 1);
	mlx_set_instance_depth(data->player.mm->instances, 3);
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
	fp_txt = mlx_put_string(data->mlx, fp, WIDTH - 30, 10);
	mlx_set_instance_depth(string->instances, 5);
	mlx_set_instance_depth(fp_txt->instances, 5);
	free(dir);
	free(fp);
}

static void	clear(t_data *data)
{
	ft_memset(data->floor->pixels, 0, sizeof(data->floor->pixels));
	ft_memset(data->wall_full->pixels, 0, (WIDTH * HEIGHT) * 4);
}

void	draw_game(t_data	*data)
{
	static double	pos_y = 0.0;
	static double	pos_x = 0.0;
	static double	dir_x = 0.0;
	static double	dir_y = 0.0;
	static double	pitch = 0;

	if ((data->player.pos[0] != pos_y || data->player.pos[1] != pos_x)
		|| data->player.dir[1] != dir_y || data->player.dir[0] != dir_x
		|| data->player.pitch != pitch)
	{
		clear(data);
		multi_caster(data);
		compass(data);
		data->player.mm->instances->x = floor(data->player.pos[1]) * MM;
		data->player.mm->instances->y = floor(data->player.pos[0]) * MM;
		pos_y = data->player.pos[0];
		pos_x = data->player.pos[1];
		dir_x = data->player.dir[0];
		dir_y = data->player.dir[1];
	}
	else
		return ;
}

void	game_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT_CONTROL))
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_exit("", 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_look_left(data, ROT);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_look_right(data, ROT);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_move_north(data, SPEED);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_move_south(data, SPEED);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_move_west(data, SPEED);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_move_east(data, SPEED);
	draw_game(data);
}
