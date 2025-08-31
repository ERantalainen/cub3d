/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:29:43 by erantala          #+#    #+#             */
/*   Updated: 2025/08/31 01:54:45 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/include/libft.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define WIDTH	800
# define HEIGHT	600
# define TXT	128
# define TILE 256
# define MM 10
# define SPEED 0.05
# define ROT 0.05

# define DEFMAP "1111111111111111 \
				100111000011110111 \
				101111000111110001 \
				100001011100000111 \
				11100101 100000101 \
				1110000111000000N1 \
				111111111111111111"
# define DNO "./textures/dlv_metaltrm4a.png"
# define DSO "./textures/dlv_metaltrm1b.png"
# define DWE "./textures/dlv_metalpan4a.png"
# define DEA "./textures/dlv_metaltrm4c.png"
# define FLOOR "./textures/dlv_ground1d.png"
# define CEIL "./textures/dlv_wood2c.png"

# define PI 3.14159

# define ARENA_SIZE 32768
# define ALIGNMENT 8

typedef struct s_arena
{
	size_t		max;
	size_t		index;
	char		data[];
}				t_arena;

typedef	struct s_ray
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
	long	height;
	int		bottom;
	long		top;
	double	point;
	int		tex_x;
	int		side;
	int		txt_size;
	float	rayDirX[2];
	float	rayDirY[2];
	float	F_StepX;
	float	F_StepY;
	float	floorX;
	float	floorY;
	float	f_dist;
	int		floorTX;
	int		floorTY;
}	t_ray;


typedef	struct s_player
{
	double		pos[2];
	int			map_pos[2];
	double		dir[2];
	double		angleX;
	double		angleY;
	double		planeX;
	double		planeY;
	double		pdx;
	double		pdy;
	t_ray		ray;
	mlx_image_t	*mm;
	mlx_image_t	*arrow;
}	t_player;

#include <pthread.h>

typedef struct s_data
{
	mlx_texture_t	*wall_txt[4];
	mlx_texture_t	*floor_txt;
	mlx_texture_t	*ceil_txt;
	mlx_image_t		*wall_img[4];
	unsigned int	f_c;
	unsigned int	r_c;
	mlx_t			*mlx;
	char			**map;
	int				map_w;
	int				map_h;
	t_player		player;
	mlx_image_t		*wall_full;
	mlx_image_t		*minimap;
	unsigned int	buffer[HEIGHT + 1][WIDTH + 1];
	unsigned int	wabuffer[HEIGHT + 1][WIDTH + 1];
	unsigned int	temps[WIDTH/400][WIDTH][HEIGHT];
	pthread_t		cast[WIDTH/400];
	volatile int	n;
}	t_data;

// Default

t_data	*load_default();

// Data

t_data	*get_data();

// Utility

void	*arena_malloc(size_t n);
void	ft_exit(char *s, int code);
void	ft_close(void *s);
char	*ft_stradd(char *s1, char *s2);
unsigned int make_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

// Setting up game

void	load_game(t_data	*data);
void	make_player(t_data *data);

// Main game functionality

void	start_game(t_data *data);
void	ft_look_right(t_data *data, double rot);
void	ft_look_left(t_data *data, double rot);
void	cursor_pos(double xpos, double ypos, void *param);

void	ft_move_north(t_data *data);
void	ft_move_south(t_data *data);
void	ft_move_west(t_data *data);
void	ft_move_east(t_data *data);

void	render_minimap(t_data *data);

// RayCasting

void	render_frame(t_data	*data, t_player player, int x, int tex_x);
void	RayCaster(t_player player);
void	floor_caster(t_data *data, t_ray ray, t_player player);
unsigned int get_color(mlx_texture_t *txt, int index);
void	multi_caster(t_data	*data);
void	*multi_floor(void	*param);
#endif