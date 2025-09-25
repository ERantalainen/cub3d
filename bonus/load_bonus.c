/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 22:29:58 by erantala          #+#    #+#             */
/*   Updated: 2025/09/17 18:14:53 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	load_images(t_data	*data)
{
	data->wall_img[NO] = mlx_texture_to_image(data->mlx, data->wall_txt[NO]);
	if (!data->wall_img[NO])
		ft_exit("Error initializing images", 1);
	data->wall_img[SO] = mlx_texture_to_image(data->mlx, data->wall_txt[SO]);
	if (!data->wall_img[SO])
		ft_exit("Error initializing images", 1);
	data->wall_img[WE] = mlx_texture_to_image(data->mlx, data->wall_txt[WE]);
	if (!data->wall_img[WE])
		ft_exit("Error initializing images", 1);
	data->wall_img[EA] = mlx_texture_to_image(data->mlx, data->wall_txt[EA]);
	if (!data->wall_img[EA])
		ft_exit("Error initializing images", 1);
	data->wall_full = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->wall_full)
		ft_exit("ERROR", 1);
	data->floor = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->floor)
		ft_exit("Error", 1);
}

char	find_start_pos(t_data	*data)
{
	int	row;
	int	col;

	row = 0;
	while (data->map[row])
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

	load_images(data);
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
}
