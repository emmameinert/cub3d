
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
	int	m_widht;
	int	m_height;
	t_color	*ceiling;
	t_color	*floor;
	t_coord **map;
}	t_textures;

//START
void		run_program(char **argv);

//INPUT
void		validate_parse_file(int fd);
char		*parse_textures(int fd, t_textures **texture);
void		parse_map(int fd, t_textures **textures, char *line);
void		parse_array(t_textures **texture, t_node **map);

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

//MEMORY
t_textures	*init_info(void);

#endif
