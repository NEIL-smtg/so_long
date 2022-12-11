/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:40:48 by suchua            #+#    #+#             */
/*   Updated: 2022/12/09 00:40:48 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_win	win;

	if (ac == 2)
	{
		ft_check_map_path(av[1]);
		get_map(av[1], &win);
	}
	else
	{
		ft_printf("map path not found\n");
		exit(EXIT_FAILURE);
	}
}
