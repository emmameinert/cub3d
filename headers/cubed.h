
#ifndef CUBED_H
# define CUBED_H

# include "../libft/libft.h"
# include "lst.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_textures
{
	int	no;
	int	so;
	int	ea;
	int	we;
	t_color	*ceiling;
	t_color	*floor;
}	t_textures;

typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_img;

typedef struct s_mlx
{
	void *mlx;
	void *window;
	t_img *img;
}	t_mlx;

//START
void		run_program(char **argv);

//INPUT
void		validate_parse_file(int fd);
t_textures	*parse_textures(int fd);
void		parse_map(int fd, t_node **map);

// VALIDATION
int		texture_file_existence(int fd, char *msg, char *file);
void	validate_texture_count(int counter);
int		valid_char(char ch);
void	validate_map(t_node **map);

//UTILS

//FILES
int			open_file(char *file);
void		close_file(int fd);
void		suffix_cmp(char *file, char *suffix);

t_mlx	*init_mlx_wind(void);
t_img	*init_img(t_mlx **mlx);
int		on_destroy(t_mlx **mlx);
int		key_hook(int keycode, t_mlx **mlx);

//MEMORY
t_textures *init_info(void);

// EXIT
void	exit_success(t_mlx **mlx);
void	exit_failure(void);

#endif
