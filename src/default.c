/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:54:54 by erantala          #+#    #+#             */
/*   Updated: 2025/08/18 18:30:19 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	load_walls(t_data	*data);

t_data	*load_default()
{
	t_data			*data;
	mlx_t			*mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_set_setting(MLX_FULLSCREEN, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		ft_exit("Error initializing mlx", 1);
	data = get_data();
	data->mlx = mlx;
	load_walls(data);
	data->map = ft_split(DEFMAP, '\n');
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
	data->ceiling[0] = 0;
	data->ceiling[1] = 255;
	data->ceiling[2] = 0;
	data->floor[0] = 200;
	data->floor[1] = 200;
	data->floor[2] = 200;
}
