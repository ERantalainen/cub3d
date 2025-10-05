/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:43:47 by erantala          #+#    #+#             */
/*   Updated: 2025/10/05 16:00:04 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	set_player_spawn(t_data *data)
{
	t_spawn	spawn;

	spawn = find_spawn(data->map, data->map_h);
	data->player.pos[0] = spawn.row + 0.5;
	data->player.pos[1] = spawn.col + 0.5;
	set_player_direction(data, spawn.c);
	data->map[spawn.row][spawn.col] = '0';
}

static void	init_player_and_images(t_data *data)
{
	ft_memset(&data->player, 0, sizeof(t_player));
	ft_memset(&data->player.ray, 0, sizeof(t_ray));
	set_player_spawn(data);
	make_player(data);
	data->minimap = mlx_new_image(data->mlx, 11 * MM,
			11 * MM);
	if (!data->minimap)
		ft_exit("Error creating minimap image", 1);
	data->wall_full = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->wall_full)
		ft_exit("Error creating wall texture", 1);
	data->floor = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->floor)
		ft_exit("Error creating floor image", 1);
}

static void	set_map_dimensions(t_data *data)
{
	int	j;
	int	len;

	data->map_w = 0;
	j = 0;
	while (j < data->map_h)
	{
		len = (int)ft_strlen(data->map[j]);
		if (len > data->map_w)
			data->map_w = len;
		j++;
	}
}

t_data	*load_data(const char *filename)
{
	t_data	*data;

	data = get_data();
	init_mlx_and_data(data);
	parse_cub_file(data, filename);
	set_map_dimensions(data);
	init_player_and_images(data);
	flood_fill(data->map, round(data->player.pos[0]),
		round(data->player.pos[1]));
	return (data);
}
