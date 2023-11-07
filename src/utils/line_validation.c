/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_Validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:12:50 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 15:13:49 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	validate_line(char *line)
{
	char	*temp;

	temp = ft_strtrim(line, "\n\t 1NSEW");
	if (ft_strlen(temp) > 0)
	{
		free(temp);
		free(line);
		ft_put_error_exit("Invalid input file");
	}
	free(temp);
}
