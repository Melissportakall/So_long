/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:14:46 by mportaka          #+#    #+#             */
/*   Updated: 2024/02/24 14:34:43 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void	path_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		path_error("Error\nInvalid path");
	}
	else
		close(fd);
}

int	main(int argc, char **argv)
{
	t_main	*main;

	check_parameters(argc, argv);
	path_check(argv[1]);
	main = (t_main *)malloc(sizeof(t_main));
	if (!main)
		return (0);
	if (main_initiliazer(argv[1], &main))
		return (free(main), 0);
	map_checker(main);
	if (virtual_map(main, 0, 0))
		return (ft_free(main), 0);
	if (draw_map(main))
		return (write(2, "Error\nxpm file bot found", 24), 0);
	mlx_hook(main->win, 2, 1L << 0, key_hook, main);
	mlx_loop_hook(main->mlx, render, main);
	mlx_hook(main->win, EXIT, 0, ft_x_button, main);
	mlx_loop(main->mlx);
}
