/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:14:29 by mportaka          #+#    #+#             */
/*   Updated: 2024/02/24 14:31:58 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

void	path_error(char *errormsg)
{
	int	i;

	i = 0;
	while (errormsg[i])
	{
		write(2, &errormsg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(0);
}

void	check_parameters(int ac, char **av)
{
	int	map_name_len;

	if (ac > 2)
		path_error("Error\nToo many arguments (It should be only two)");
	if (ac < 2)
		path_error("Error\nThe Map file is missing.");
	map_name_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_name_len - 4], ".ber", 4))
		path_error("Error\nMap file extention is wrong (It should be .ber).");
}
