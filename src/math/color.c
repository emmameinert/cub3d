/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:36 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/13 11:40:12 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

char	**prepare_string(char *line, int start)
{
	char	*input;
	char	*trimmed_input;
	char	**double_trim;
	char	**numbers;

	input = ft_substr(line, start, ft_strlen(line) - start);
	trimmed_input = ft_strtrim(input, "\n\t FC");
	free(input);
	double_trim = ft_split(trimmed_input, ' ');
	free(trimmed_input);
	input = add_color_string(double_trim);
	free_char_array(double_trim);
	numbers = ft_split(input, ',');
	free(input);
	return (numbers);
}

char	*add_color_string(char **line)
{
	char	*added_string;
	char	*copy;
	int		i;

	i = 0;
	if (!line[0])
		return (NULL);
	added_string = ft_strdup(line[i]);
	while (line[i] && line[i + 1])
	{
		copy = ft_strjoin(added_string, line[i + 1]);
		free(added_string);
		added_string = ft_strdup(copy);
		free(copy);
		i++;
	}
	return (added_string);
}

void	calculate_colors(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	if (i > 3)
		ft_put_error_exit("Invalid number of values for the color");
}

void	ft_parse_color(t_color *color, int *colour)
{
	color->r = colour[0];
	color->g = colour[1];
	color->b = colour[2];
	color->draw_color = ft_rgbtocolor(*color);
}

long	ft_rgbtocolor(t_color rgb)
{
	long	color;

	color = ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
	return (color);
}
