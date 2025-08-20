/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:29:43 by erantala          #+#    #+#             */
/*   Updated: 2025/08/20 18:43:34 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/include/libft.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define WIDTH	800
# define HEIGHT	600

# define TILE 256
# define SPEED 0.1

# define DEFMAP "1111111111111111 \
				100111000011110111 \
				101111000111110001 \
				100001011100000111 \
				11100101 100000101 \
				1110000111000000N1 \
				111111111111111111"
# define DNO "./textures/dlv_metaltrm4a.png"
# define DSO "./textures/dlv_metaltrm3c.png"
# define DWE "./textures/dlv_metaltrm4c.png"
# define DEA "./textures/dlv_metaltrm4c.png"
# define PI 3.14159

# define ARENA_SIZE 32768
# define ALIGNMENT 8

typedef struct s_arena
{
	size_t		max;
	size_t		index;
	char		data[];
}				t_arena;

typedef	struct s_caster
{
	double	rayX;
	double	rayY;
	double	sideX;
	double	sideY;
	double	deltaX;
	double	deltaY;
	int		stepX;
	int		stepY;
	double	distance;
	int		height;
	int		bottom;
	int		top;
}	t_caster;


typedef	struct s_player
{
	double		pos[2];
	int			map_pos[2];
	double		dir[2];
	double		plane[2];
	double		pdx;
	double		pdy;
	t_caster	ray;
}	t_player;

typedef struct s_data
{
	mlx_texture_t	*wall_txt[4];
	mlx_image_t		*wall_img[4];
	int				floor[3];
	int				ceiling[3];
	mlx_t			*mlx;
	char			**map;
	t_player		player;
}	t_data;

// Default

t_data	*load_default();

// Data

t_data	*get_data();

// Utility

void	*arena_malloc(size_t n);
void	ft_exit(char *s, int code);
void	ft_close(void *s);

// Setting up game

void	load_game(t_data	*data);

// Main game functionality

void	start_game(t_data *data);
void	ft_look_right(t_data *data);
void	ft_look_left(t_data *data);

void	ft_move_north(t_data *data);
void	ft_move_south(t_data *data);
void	ft_move_west(t_data *data);
void	ft_move_east(t_data *data);

// RayCasting

void	render_frame(t_data	*data, t_player player, int x);
void	RayCaster(t_player player);

#endif