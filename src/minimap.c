/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:24:24 by erantala          #+#    #+#             */
/*   Updated: 2025/08/22 15:54:24 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	mini_helper(t_data *data, unsigned int color, int x, int y)
{
	int	col;
	int	row;

	row = 0;
	while (row < MM)
	{
		col = 0;
		while (col < MM)
		{
			if (row == 0 || row == MM - 1 || col == 0 || col == MM - 1)
				mlx_put_pixel(data->minimap, y + col, x + row, make_color(255, 0, 0, 255));
			else
				mlx_put_pixel(data->minimap, y + col, x + row, color);
			col++;
		}
		row++;
	}
}

void	make_player(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	data->player.mm = mlx_new_image(data->mlx, MM - 1, MM - 1);
	while (row < MM - 1)
	{
		col = 0;
		while (col < MM - 1)
		{
			mlx_put_pixel(data->player.mm, col, row, make_color(0, 255, 0, 255));
			col++;
		}
		row++;
	}
}

void	render_minimap(t_data *data)
{
	int	x;
	int	y;
	static mlx_image_t	*string;

	y = 0;
	mlx_delete_image(data->mlx, data->minimap);
	mlx_delete_image(data->mlx, string);
	data->minimap = mlx_new_image(data->mlx, data->map_w * MM, data->map_h * MM);
	if (!data->minimap)
		ft_exit("error", 1);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mini_helper(data, make_color(0, 0, 0, 255), y * MM, x * MM);
			else
				mini_helper(data, make_color(255, 255, 255, 255), y * MM, x * MM);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->minimap, 0, 0);
	mlx_set_instance_depth(data->minimap->instances, 2);
	string = mlx_put_string(data->mlx, ft_itoa(data->player.dir[0] * (180 / PI)), WIDTH / 2 - 20, 50);
}
