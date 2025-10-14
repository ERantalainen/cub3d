/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:29:43 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 16:09:54 by dimendon         ###   ########.fr       */
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

# define PI 3.14159

# define ARENA_SIZE 32768
# define ALIGNMENT 8

typedef unsigned int	t_uint;

typedef struct s_arena
{
	size_t		max;
	size_t		index;
	char		data[];
}				t_arena;

typedef struct s_ray
{
	double	ray_x;
	double	ray_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	distance;
	long	height;
	int		bottom;
	long	top;
	double	point;
	int		tex_x;
	int		side;
	int		txt_size;
	float	ray_dirx[2];
	float	ray_diry[2];
	float	f_stepx;
	float	f_stepy;
	float	floor_x;
	float	floor_y;
	float	f_dist;
	int		floor_tx;
	int		floor_ty;
}	t_ray;

typedef struct s_player
{
	double		pos[2];
	int			map_pos[2];
	double		dir[2];
	double		angle_x;
	double		angle_y;
	double		plane_x;
	double		plane_y;
	double		pdx;
	double		pdy;
	t_ray		ray;
	mlx_image_t	*mm;
	mlx_image_t	*arrow;
}	t_player;

typedef struct s_data
{
	mlx_texture_t	*wall_txt[4];
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
}	t_data;

typedef struct s_spawn
{
	int		row;
	int		col;
	char	c;
}	t_spawn;

// Data

/*Returns a pointer to the data struct*/
t_data			*get_data(void);
void			init_mlx_and_data(t_data *data);

/* Frees the data struct pointed to by t_data *data*/
void			free_data(t_data *data);

// Utility

/* Allocates N bytes from the memory arena*/
void			*arena_malloc(size_t n);
/* Frees all memory arenas*/
void			free_arenas(void);
/* Exits the program.
	int code - exit code to exit with
	char *s - string to print to stderr, if NULL won't print anything*/
void			ft_exit(char *s, int code);
void			ft_close(void *s);
char			*ft_stradd(char *s1, char *s2);

/* Creates an unsigned int color value that  can be used with mlx
	unsigned char r - red channel
	unsigned char g - green channel
	unsigned char b - blue channel
	unsigned char a - alpha channel */
unsigned int	make_color(t_uint r, t_uint g, unsigned int b, unsigned int a);

// Setting up game

t_data			*load_data(const char *filename);
void			make_player(t_data *data);
t_spawn			find_spawn(char **map, int map_h);
void			set_player_direction(t_data *data, char c);

// Main game functionality

void			start_game(t_data *data);
void			ft_look_right(t_data *data, double rot);
void			ft_look_left(t_data *data, double rot);
void			cursor_pos(double xpos, double ypos, void *param);
void			ft_move_north(t_data *data);
void			ft_move_south(t_data *data);
void			ft_move_west(t_data *data);
void			ft_move_east(t_data *data);
void			render_minimap(t_data *data);

// RayCasting

void			render_frame(t_data	*data, t_player player, int x, int tex_x);
/* Render the frame after raycasting math is done
	int x - the x cordinate of the slice being rendered
	tex_x - the x position on the texture being cassted*/
void			raycaster(t_player player);
/* Gets the color of a pixel
	int index - the index in texture->pixels array
	mlx_texture_t *txt - the texture to find pixel from*/
unsigned int	get_color(mlx_texture_t *txt, int index);
void			multi_caster(t_data	*data);

// Parsing
void			parse_cub_file(t_data *data, const char *filename);
unsigned int	parse_color(char *s);

// Parsing Helpers
char			**read_lines(const char *filename);
int				count_map_lines(char **lines, int start);
void			free_rest(t_data *data, char **line, int j, int i);

// Parsing Utility
int				flood_fill(char **map, int row, int col);
void			require_assets_present(t_data *d, int c[2], char **ln, int i);
int				parse_asset_line(t_data *data, char *line, int have_col[2]);
void			parse_color_line(t_data *data, char *line, int *f, int *c);
void			parse_texture_line(t_data *data, char *line);

#endif
