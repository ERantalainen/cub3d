/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:29:43 by erantala          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/09/11 16:29:02 by erantala         ###   ########.fr       */
=======
/*   Updated: 2025/09/17 14:52:18 by dimendon         ###   ########.fr       */
>>>>>>> Stashed changes
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
/*Returns a pointer to the data struct*/
t_data	*get_data();

// Utility

/* Allocates N bytes from the memory arena*/
void	*arena_malloc(size_t n);
/* Exits the program.
	int code - exit code to exit with
	char *s - string to print to stderr, if NULL won't print anything*/
void	ft_exit(char *s, int code);
/* Function hook for MLX close*/
void	ft_close(void *s);
/*Adds string s1 to string s2, using the memory arena */
char	*ft_stradd(char *s1, char *s2);
/* Creates an unsigned int color value that  can be used with mlx
	unsigned char r - red channel
	unsigned char g - green channel
	unsigned char b - blue channel
	unsigned char a - alpha channel */
unsigned int make_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

// Setting up game

/* Loads initial game  data from data struct*/
void	load_game(t_data	*data);
/* Creates the player icon for the minimap*/
void	make_player(t_data *data);

// Main game functionality


/* Starts the core game functionality*/
void	start_game(t_data *data);
/* Function for handling the player looking right
	rot - speed of turn*/
void	ft_look_right(t_data *data, double rot);
/* Function for handling the player looking left
	rot - speed of turn*/
void	ft_look_left(t_data *data, double rot);
/* MLX mousehook to track the mouse movement*/
void	cursor_pos(double xpos, double ypos, void *param);

/* Movement function for moving forward*/
void	ft_move_north(t_data *data);
/* Movement function for moving backwards*/
void	ft_move_south(t_data *data);
/* Movement function for moving left*/
void	ft_move_west(t_data *data);
/* Movement function for moving right*/
void	ft_move_east(t_data *data);
/* Minimap function to create the minimap*/
void	render_minimap(t_data *data);

// RayCasting

/* Render the frame after raycasting math is done
	int x - the x cordinate of the slice being rendered
	tex_x - the x position on the texture being cassted*/
<<<<<<< Updated upstream
void	render_frame(t_data	*data, t_player player, int x, int tex_x);
/* Core raycasting loop, calculates the height of the walls*/
void	RayCaster(t_player player);
/* Gets the color of a pixel
	int index - the index in texture->pixels array
	mlx_texture_t *txt - the texture to find pixel from*/
unsigned int get_color(mlx_texture_t *txt, int index);
#endif
=======
void			ray_caster(t_player player);
void			floor_caster(t_data *data, t_ray ray, t_player player);
/* Gets the color of a pixel
	int index - the index in texture->pixels array
	mlx_texture_t *txt - the texture to find pixel from*/
unsigned int	get_color(mlx_texture_t *txt, int index);
void			multi_caster(t_data	*data);

// Parsing
void			parse_cub_file(t_data *data, const char *filename);
unsigned int 	parse_color(char *s);

// Parsing Helpers
char 			**read_lines(const char *filename);
int				count_map_lines(char **lines, int start);

// Parsing Utility
int				flood_fill(char **map, int row, int col);
void 			require_assets_present(t_data *data, int have_f, int have_c);
int				parse_asset_line(t_data *data, char *line, int *have_f, int *have_c);
void			parse_color_line(t_data *data, char *line, int *have_f, int *have_c);
void			parse_texture_line(t_data *data, char *line);

#endif
>>>>>>> Stashed changes
