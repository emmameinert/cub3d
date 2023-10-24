/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:56:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_put_error_exit("Failed to open the file");
	return (fd);
}

void	close_file(int fd)
{
	if (close(fd) == -1)
		ft_put_error_exit("Failed to close the file");
}

void	suffix_cmp(char *file, char *suffix)
{
	int		len;
	char	*file_ending;
	char	*file_trimmed;

	file_trimmed = ft_strtrim(file, "\t\n ");
	len = ft_strlen(file_trimmed);
	file_ending = ft_substr(file_trimmed, len - 4, 4);
	if (ft_strncmp_all(file_ending, suffix))
	{
		free(file_ending);
		ft_put_error_exit("Invalid suffix as input");
	}
	free(file_trimmed);
	free(file_ending);
}
