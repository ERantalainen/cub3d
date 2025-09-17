/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:43:47 by erantala          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/09/10 14:58:20 by erantala         ###   ########.fr       */
=======
/*   Updated: 2025/09/17 14:44:29 by dimendon         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	find_start_pos(t_data	*data)
{
<<<<<<< Updated upstream
	int	row;
	int	col;

	row = 0;
	for (int i = 0; data->map[i]; i++)
		puts(data->map[i]);
	while (data->map[row])
=======
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
	data->minimap = mlx_new_image(data->mlx, data->map_w * MM, data->map_h
			* MM);
	if (!data->minimap)
		ft_exit("Error creating minimap image", 1);
	data->wall_full = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->wall_full)
		ft_exit("Error creating main image", 1);
}

static void	set_map_dimensions(t_data *data)
{
	int	j;
	int	len;

	data->map_w = 0;
	j = 0;
	while (j < data->map_h)
>>>>>>> Stashed changes
	{
		col = 0;
		while (data->map[row][col])
		{
			if ((data->map[row][col] == 'N' || data->map[row][col] == 'S')
			|| data->map[row][col] == 'E' || data->map[row][col] == 'W')
			{
				data->player.pos[1] = col;
				data->player.pos[0] = row;
				return (data->map[row][col]);
			}
			col++;
		}
		row++;
	}
	ft_exit("Invalid map: no start pos", 1);
	return (0);
}

void	load_game(t_data	*data)
{
	char	dir;

<<<<<<< Updated upstream
	dir = find_start_pos(data);
	if (dir == 'S')
	{
		data->player.dir[0] = (3 * PI / 2);
		data->player.dir[1] = 0.0;
	}
	if (dir == 'N')
	{
		data->player.dir[0] = (PI / 2);
		data->player.dir[1] = 0.0;
	}
	if (dir == 'W')
	{
		data->player.dir[0] = PI;
		data->player.dir[1] = 0.0;
	}
	if (dir == 'E')
	{
		data->player.dir[0] = 0.0;
		data->player.dir[1] = 0.0;
	}
	
	start_game(data);
=======
	data = get_data();
	init_mlx_and_data(data);
	parse_cub_file(data, filename);
	set_map_dimensions(data);
	init_player_and_images(data);
	flood_fill(data->map, floor(data->player.pos[0]),
		floor(data->player.pos[1]));
	return (data);
>>>>>>> Stashed changes
}
