/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:45 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:48:46 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	validate_parse_input(int fd, t_info **info)
{
	char		*line;

	line = NULL;
	line = parse_textures(fd, info);
	parse_map(fd, info, line);
	parse_player(&(*info)->player);
}
