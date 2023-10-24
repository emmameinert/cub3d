/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:38 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:50:39 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cubed.h"

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		ft_put_error_exit("Expecting one filename as an argmunent.");
	else if (argv[1][0] == '\0')
		return (0);
	else
		run_program(argv);
	return (0);
}
