/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_score_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:21:22 by suchua            #+#    #+#             */
/*   Updated: 2022/12/19 17:21:22 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_score(t_win *win, int i, int j)
{
	int	x;
	int	y;

	win->player->score++;
	win->map->c--;
	win->map->mapping[i][j] = '0';
	if (!win->map->c)
	{
		x = 0;
		y = 0;
		mlx_destroy_image(win->mlx, win->img->ex_img);
		win->img->ex_img = mlx_xpm_file_to_image(win->mlx,
				"xpm/exit_open.xpm", &x, &y);
	}
}

int	game_over(t_win *win)
{
	if (win->map->c > 0)
		return (0);
	ft_printf("YOU WON THIS GAME !!!\n");
	destroy_everything(win);
	system("leaks so_long");
	exit(EXIT_FAILURE);
}
