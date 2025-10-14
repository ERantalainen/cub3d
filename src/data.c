/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:43:13 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 12:57:01 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	init_mlx_and_data(t_data *data)
{
	mlx_t	*mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!mlx)
		ft_exit("Error initializing mlx", 1);
	data->mlx = mlx;
}

void	free_data(t_data *data)
{
	if (data->map)
		ft_frearr((void **)data->map, data->map_h);
	if (data->wall_txt[0])
		mlx_delete_texture(data->wall_txt[0]);
	if (data->wall_txt[1])
		mlx_delete_texture(data->wall_txt[1]);
	if (data->wall_txt[2])
		mlx_delete_texture(data->wall_txt[2]);
	if (data->wall_txt[3])
		mlx_delete_texture(data->wall_txt[3]);
	if (data->mlx)
		mlx_terminate(data->mlx);
}
