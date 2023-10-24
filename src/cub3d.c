/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:33 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:50:34 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cubed.h"

void	run_program(char **argv)
{
	int fd;
	t_info *info;

	suffix_cmp(argv[1], ".cub");
	fd = open_file(argv[1]);
	info = init_info();
	validate_parse_input(fd, &info);
	close_file(fd);
	render(&info);
	hook_loop(&info);
}
