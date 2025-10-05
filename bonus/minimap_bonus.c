/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:24:24 by erantala          #+#    #+#             */
/*   Updated: 2025/10/05 17:05:03 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	mini_helper(t_data *data, unsigned int color, int x, int y)
{
	int				col;
	int				row;
	unsigned int	edge;

	edge = make_color(255, 0, 0, 255);
	row = 0;
	while (row < MM)
	{
		col = 0;
		while (col < MM)
		{
			if (row == 0 || row == MM - 1 || col == 0 || col == MM - 1)
				mlx_put_pixel(data->minimap, y + col, x + row, edge);
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

	if (data->player.mm == NULL)
	{
		data->player.mm = mlx_new_image(data->mlx, MM - 1, MM - 1);
		if (!data->player.mm)
			ft_exit("Error creating player minimap image", 1);
		row = 0;
		while (row < MM - 1)
		{
			col = 0;
			while (col < MM - 1)
			{
				mlx_put_pixel(data->player.mm, col, row,
					make_color(0, 255, 0, 255));
				col++;
			}
			row++;
		}
	}
}

void	render_minimap(t_data *data)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	pos_y = 0;
	y = (int)fmax(0, floor(data->player.pos[0]) - 5);
	while (data->map[y] && y < floor(data->player.pos[0]) + 5)
	{
		x = (int)fmax(0, floor(data->player.pos[1]) - 5);
		pos_x = 0;
		while (data->map[y][x] && x < floor(data->player.pos[1]) + 5)
		{
			if (data->map[y][x] == '1')
				mini_helper(data, make_color(0, 0, 0, 255),
					pos_y * MM, pos_x * MM);
			else if (data->map[y][x] != ' ')
				mini_helper(data, make_color(255, 255,
						255, 255), pos_y * MM, pos_x * MM);
			x++;
			pos_x++;
		}
		pos_y++;
		y++;
	}
}
