
#ifndef CUBED_H
# define CUBED_H

# include "../libft/libft.h"
# include "lst.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <math.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
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
};

enum e_type
{
	NO = 1,
	SO = 2,
	EA = 3,
	WE = 4
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	double	x;
	double	y;
	int		angle;
	double	dir_y;
	double	dir_x;
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

//START
void		run_program(char **argv);

// MATH
double		ft_dtorad(int angle);

//INPUT
void		validate_parse_input(int fd, t_info **info);
char		*parse_textures(int fd, t_info **texture);
void		parse_map(int fd, t_info **textures, char *line);
void		parse_array(t_info **texture, t_node **map);
void		parse_matrices(t_info **info);

// VALIDATION
char    *texture_file_existence(char *msg, char *file);
void	validate_texture_count(int counter);
int		valid_char(char ch);
void	validate_map(t_node **map, t_info **texture);
void	flood_fill(t_info **texture, int y, int x);

//DRAW
void	draw_minimap(t_info **info);
void	draw_background(t_info **info);

//FILES
int			open_file(char *file);
void		close_file(int fd);
void		suffix_cmp(char *file, char *suffix);

// MLX
void	init_mlx(t_info **info);
int		on_destroy(t_mlx **mlx);
int		key_hook(int keycode, t_mlx **mlx);
void	hook_loop(t_info **info);
void	put_pixel(t_info **info, int x, int y, int color);
void	render(t_info **info);

//MEMORY
t_info *init_info(void);

// EXIT
void	exit_success(t_mlx **mlx);
void	exit_failure(void);

# define BLACK 0x000000
# define WHITE 0xffffff
# define GREEN 0x009933
# define RED 0xff0000
# define TURQUOISE 0x00cccc
# define YELLOW 0xffff00
# define PURPLE 0x800080
# define PINK 0xff33cc
# define TOMATO  0xff6347
# define LEMON_CHIFFON 0xfffacd
# define ROYAL_BLUE 0x4169e1
# define COLOR_BLACK     0x000000
# define COLOR_WHITE     0xFFFFFF
# define COLOR_RED       0xFF0000
# define COLOR_GREEN     0x00FF00
# define COLOR_BLUE      0x0000FF
# define COLOR_YELLOW    0xFFFF00
# define COLOR_CYAN      0x00FFFF
# define COLOR_MAGENTA   0xFF00FF
# define COLOR_GRAY      0x808080
# define COLOR_LIGHTGRAY 0xC0C0C0
# define COLOR_DARKGRAY  0x404040
# define COLOR_BROWN     0x964B00
# define COLOR_ORANGE    0xFFA500
# define COLOR_PINK      0xFFC0CB
# define COLOR_PURPLE    0x800080
# define COLOR_LIME      0x00FF00
# define COLOR_NAVY      0x000080
# define COLOR_TEAL      0x008080
# define COLOR_OLIVE     0x808000
# define COLOR_MAROON    0x800000
# define COLOR_AQUA      0x00FFFF
# define COLOR_SILVER    0xC0C0C0
# define COLOR_LIGHTBLUE 0xADD8E6
# define COLOR_GOLD      0xFFD700
# define COLOR_VIOLET    0xEE82EE

#endif
