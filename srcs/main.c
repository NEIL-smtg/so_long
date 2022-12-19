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
				win->player->p_x = j;
				win->player->p_y = i;
				return ;
			}
		}
	}
}

void	init(t_win *win, int *x, int *y)
{
	win->win_h = win->map->h * 64;
	win->win_w = win->map->w * 64;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->win_w, win->win_h, "SOOOOO FUCKING LOOOOOONG !!!");
	win->player = ft_calloc(1, sizeof(t_player));
	get_player_pos(win);
	win->player->score = 0;
	win->player->p_img = mlx_xpm_file_to_image(win->mlx, "xpm/pr.xpm", x, y);
	win->map->empty_img = mlx_xpm_file_to_image(win->mlx, "xpm/floor2.xpm", x, y);
	win->map->w_img = mlx_xpm_file_to_image(win->mlx, "xpm/wall.xpm", x, y);
	win->map->c_img = mlx_xpm_file_to_image(win->mlx, "xpm/coin.xpm", x, y);
	win->map->ex_img = mlx_xpm_file_to_image(win->mlx, "xpm/door1.xpm", x, y);
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
		mlx_key_hook(win.win, key_on_pressed, &win);
		mlx_loop(win.mlx);
	}
	else
	{
		ft_printf("map path not found\n");
		exit(EXIT_FAILURE);
	}
}
