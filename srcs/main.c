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

void	set_player_pos(t_win *win)
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
				win->player->p_i = i;
				win->player->p_j = j;
				win->player->ori_pi = i;
				win->player->ori_pj = j;
				return ;
			}
		}
	}
}

int	destroy_exit(t_win *win)
{
	destroy_everything(win);
	exit(EXIT_FAILURE);
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
		mlx_hook(win.win, KEY_PRESS, (1L << 0), key_on_pressed, &win);
		mlx_hook(win.win, KEY_RELEASE, (1L << 1), stop_animation, &win);
		mlx_hook(win.win, 17, (1L << 0), destroy_exit, &win);
		mlx_loop_hook(win.mlx, animation, &win);
		mlx_loop(win.mlx);
	}
	else
	{
		ft_putstr_fd("Error !!\nWrong arguments..\n", 2);
		exit(EXIT_FAILURE);
	}
}
