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

void	get_player_pos(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->map->mapping[++i])
	{
		j = -1;
		while (win->map->mapping[i][++j])
		{
			if (win->map->mapping[i][j] == 'P')
			{
				// win->player->p_x = j * 64;
				// win->player->p_y = i * 64;
				win->player->p_i = i;
				win->player->p_j = j;
				return ;
			}
		}
	}
}

int	main(int ac, char **av)
{
	t_win	win;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (ac == 2)
	{
		ft_check_map_path(av[1]);
		get_map(av[1], &win);
		init(&win, &x, &y);
		render_map(&win);
		mlx_hook(win.win, 2, (1L << 0), key_on_pressed, &win);
		mlx_loop_hook(win.mlx, animation, &win);
		mlx_loop(win.mlx);
	}
	else
	{
		ft_printf("map path not found\n");
		exit(EXIT_FAILURE);
	}
}
