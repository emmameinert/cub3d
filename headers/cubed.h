
#ifndef CUBED_H
# define CUBED_H

# include "../libft/libft.h"
# include "lst.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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

//START
void		run_program(char **argv);

//INPUT
void		validate_parse_file(int fd);
int			validate_texture(char *line, t_textures **info);
void		parse_map(char *input);

//UTILS

//FILES
int			open_file(char *file);
void		suffix_cmp(char *file, char *suffix);

//MEMORY
t_textures	*init_info(void);

#endif
