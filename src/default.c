/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:54:54 by erantala          #+#    #+#             */
/*   Updated: 2025/08/23 17:51:16 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	load_walls(t_data	*data);

t_data	*load_default()
{
	t_data			*data;
	mlx_t			*mlx;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		ft_exit("Error initializing mlx", 1);
	data = get_data();
	data->mlx = mlx;
	load_walls(data);
	data->map = arena_malloc(sizeof(char *) * 12);
	ft_memset(&data->player, 0, sizeof(t_player));
	ft_memset(&data->player.ray, 0, sizeof(t_caster));
	for (int i = 0; i < 11; i++)
	{
		if (i == 0 || i == 10)
		{
			data->map[i] = arena_malloc(16);
			ft_memset(data->map[i], '1', 15);
			data->map[i][15] = 0;
		}
		else if (i == 5)
		{
			data->map[i] = arena_malloc(16);
			ft_memset(data->map[i], '1', 15);
			data->map[i][7] = '0';
			data->map[i][15] = 0;
		}
		else
		{
			data->map[i] = arena_malloc(16);
			ft_memset(data->map[i], '1', 15);
			ft_memset(data->map[i] + 1, '0', 13);
			data->map[i][15] = 0;
			if (i == 4)
				data->map[i][6] = 'N';
		}
	}
	data->map_h = 11;
	data->map_w = 15;
	data->player.pos[0] = 1.0;
	data->player.pos[1] = 1.0;
	data->player.planeY = 0.66;
	data->player.planeX = 0.0;
	data->player.pdx = -1.0;

	data->player.pdy = 0.0;
	make_player(data);
	data->wall_full = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->wall_full)
		ft_exit("WALL ERROR", 1);
	data->minimap = mlx_new_image(data->mlx, data->map_w * MM, data->map_h * MM);
	if (!data->minimap)
		ft_exit("error", 1);
	data->r_c = make_color(100, 0, 0, 255);
	data->f_c = make_color(200, 200, 200, 255);
	for(int i = 0; data->map[i]; i++)
	{
		printf("%d: %s\n", i, data->map[i]);
	}
	return (data);
}

static void	load_walls(t_data	*data)
{
	data->wall_txt[NO] = mlx_load_png(DNO);
	if (!data->wall_txt[NO])
		ft_exit("Error loading texture", 1);
	data->wall_txt[SO] = mlx_load_png(DSO);
	if (!data->wall_txt[SO])
		ft_exit("Error loading texture", 1);
	data->wall_txt[WE] = mlx_load_png(DWE);
	if (!data->wall_txt[WE])
		ft_exit("Error loading texture", 1);
	data->wall_txt[EA] = mlx_load_png(DEA);
	if (!data->wall_txt[EA])
		ft_exit("Error loading texture", 1);
}
