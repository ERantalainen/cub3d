#include "cube.h"

t_data  *get_data(void)
{
    static t_data   data;

    return (&data);
}

void	init_mlx_and_data(t_data *data)
{
	mlx_t *mlx;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!mlx)
		ft_exit("Error initializing mlx", 1);
	data->mlx = mlx;
}

