
#ifndef CUBED_H
# define CUBED_H

# include "../libft/libft.h"
# include "lst.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "color.h"
# include <math.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif

# ifndef GRID_SIZE
#  define GRID_SIZE 16
# endif

# ifndef PLR_SIZE
#  define PLR_SIZE GRID_SIZE / 2
# endif

# ifndef PLR_STEP
#  define PLR_STEP 5
# endif

# ifndef PLR_ROT_STEP
#  define PLR_ROT_STEP 10
# endif

enum e_keycode
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
	ESC = 53,
	LEFT = 0,
	DOWN = 1,
	RIGHT = 2,
	UP = 13,
	ROT_LEFT = 123,
	ROT_RIGHT = 124
};

enum e_type
{
	NO = 1,
	SO = 2,
	EA = 3,
	WE = 4
};

typedef struct s_bres
{
	int	slope_x;
	int	slope_y;
	int	dir_x;
	int	dir_y;
	int	error;
	int	errort2;
	int	x;
	int	y;
}	t_bres;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int draw_color;
}	t_color;

typedef struct s_ray
{
	double	x;
	double	y;
	double	cos;
	double	sin;
	double	angle;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	char	dir;
	double	angle;
	double	dir_y;
	double	dir_x;
	double	move_speed;
	double	rot_speed;
	int		fov;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	t_img	*img;
}	t_mlx;

typedef struct s_texture
{
	t_img	*img;
	char	*filename;
	int		type;
	int		fd;
	int		height;
	int		width;
	int		**matrix;
}	t_texture;

typedef struct s_info
{
	t_texture	*no;
	t_texture	*so;
	t_texture	*ea;
	t_texture	*we;
	int			m_width;
	int			m_height;
	int			x_index;
	int			y_index;
	t_color		*ceiling;
	t_color		*floor;
	t_coord		**map;
	t_player	*player;
	t_mlx		*mlx;
}	t_info;

// START
void		run_program(char **argv);

// MATH
double		ft_dtorad(double angle);
double		ft_angle(double angle);
int 		ft_rgbtocolor(t_color rgb);

//INPUT
void		validate_parse_input(int fd, t_info **info);
char		*parse_textures(int fd, t_info **texture);
void		parse_map(int fd, t_info **textures, char *line);
void		parse_array(t_info **texture, t_node **map);
void		parse_matrices(t_info **info);
void		parse_player(t_player **player);

// VALIDATION
char	*texture_file_existence(char *texture_file, char *msg, char *file);
void	validate_texture_count(int counter);
int		valid_char(char ch);
void	validate_map(t_node **map, t_info **texture);
void	flood_fill(t_info **texture, int y, int x);

// DRAW
void	draw_minimap(t_info **info);
void	draw_background(t_info **info, int height, int width);
void	draw_line(t_info **info, t_coord *from, t_coord *to, int color);
void	draw_player(t_info **info);
void	draw_rays(t_info **info, t_ray *ray);
void	draw_maze(t_info **info, t_ray ray);

// RAYCASTING
void	cast_rays(t_info **info);

// FILES
int			open_file(char *file);
void		close_file(int fd);
void		suffix_cmp(char *file, char *suffix);

// MLX
void	init_mlx(t_info **info);
int		on_destroy(t_info **info);
int		key_hook(int keycode, t_info **info);
void	hook_loop(t_info **info);
void	put_pixel(t_info **info, int x, int y, int color);
void	render(t_info **info);

// INIT
t_info *init_info(void);

// MOVE
void	calc_player_angle(t_info **info);
void	move_front_back(int sign_x, int sign_y, t_info **info);
void	move_side(int sign_x, int sign_y, t_info **info);
void	rot_player(int sign, t_info **info);

// EXIT
int		on_destroy(t_info **info);
void	exit_failure(void);
void	exit_success(t_mlx **mlx);

#endif
