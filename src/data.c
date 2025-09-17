/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:55:11 by erantala          #+#    #+#             */
/*   Updated: 2025/09/10 15:00:25 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

<<<<<<< Updated upstream
t_data	*get_data()
=======
t_data	*get_data(void)
>>>>>>> Stashed changes
{
	static t_data	data;

	return (&data);
<<<<<<< Updated upstream
}
=======
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
>>>>>>> Stashed changes
