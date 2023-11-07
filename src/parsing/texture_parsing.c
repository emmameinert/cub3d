/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:49:01 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 15:12:32 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static void	validate_parse_range(char *line, t_color *color, int start)
{
	char	**numbers;
	int		i;
	int		colour[3];
	char	*input;
	char	*trimmed_input;

	input = ft_substr(line, start, ft_strlen(line) - start);
	trimmed_input = ft_strtrim(input, "\n\t FC");
	free(input);
	numbers = ft_split(trimmed_input, ',');
	calculate_colors(numbers);
	i = 0;
	while (numbers[i] && i < 3)
	{
		colour[i] = ft_atoui(numbers[i]);
		if (colour[i] < 0 || colour[i] > 255)
			break ;
		i++;
	}
	free(trimmed_input);
	free_char_array(numbers);
	if (i != 3 || numbers[i])
		ft_put_error_exit("Invalid color input");
	ft_parse_color(color, colour);
}

static int	parse_floor_ceiling(char **input, char *line, t_info **info)
{
	int	i;

	i = 0;
	if (input[0][0] == 'F')
	{
		if ((*info)->floor->r != -2)
			ft_put_error_exit("Floor duplicate");
		while (line[i] != 'F')
			i++;
		validate_parse_range(line, (*info)->floor, i);
	}
	else if (input[0][0] == 'C')
	{
		if ((*info)->ceiling->r != -2)
			ft_put_error_exit("Ceiling duplicate");
		while (line[i] != 'C')
			i++;
		validate_parse_range(line, (*info)->ceiling, i);
	}
	else
		return (0);
	return (1);
}

static int	texture_comparison(char **input, t_info **info)
{
	if (!ft_strncmp_all(input[0], "NO"))
		(*info)->no->filename = texture_file_existence((*info)->no->filename,
				"NO Texture duplicate", input[1]);
	else if (!ft_strncmp_all(input[0], "SO"))
		(*info)->so->filename = texture_file_existence((*info)->so->filename,
				"SO Texture duplicate", input[1]);
	else if (!ft_strncmp_all(input[0], "EA"))
		(*info)->ea->filename = texture_file_existence((*info)->ea->filename,
				"EA Texture duplicate", input[1]);
	else if (!ft_strncmp_all(input[0], "WE"))
		(*info)->we->filename = texture_file_existence((*info)->we->filename,
				"WE Texture duplicate", input[1]);
	else
		return (0);
	return (1);
}

/// @brief checks if we have information about the textures floor or cealing
/// @param line line of the file we are reading
/// @param info here we save our general information about the map
static int	validate_texture(char *line, t_info **info)
{
	char	**input;

	input = ft_split(line, 32);
	if (!texture_comparison(input, info))
	{
		if (!parse_floor_ceiling(input, line, info))
		{
			free_char_array(input);
			return (0);
		}
	}
	free_char_array(input);
	return (1);
}

char	*parse_textures(int fd, t_info **info)
{
	char	*line;
	int		counter;

	counter = 0;
	while (fd > 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (counter == 6)
		{
			if (line[0] != '\n')
			{
				validate_line(line);
				parse_matrices(info);
				return (line);
			}
		}
		if (counter < 6)
			counter += validate_texture(line, info);
		free(line);
	}
	validate_texture_count(counter);
	parse_matrices(info);
	return (NULL);
}
