/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:46:14 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 18:28:02 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

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

size_t	ft_stralen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_data(t_data *data)
{
	if (data->map)
		ft_frearr((void **)data->map, ft_stralen(data->map));
	if (data->wall_txt[0])
		mlx_delete_texture(data->wall_txt[0]);
	if (data->wall_txt[1])
		mlx_delete_texture(data->wall_txt[1]);
	if (data->wall_txt[2])
		mlx_delete_texture(data->wall_txt[2]);
	if (data->wall_txt[3])
		mlx_delete_texture(data->wall_txt[3]);
	if (data->flr_txt)
		mlx_delete_texture(data->flr_txt);
	if (data->ceil_txt)
		mlx_delete_texture(data->ceil_txt);
	if (data->mlx)
		mlx_terminate(data->mlx);
}
