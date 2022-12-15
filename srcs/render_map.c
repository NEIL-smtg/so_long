/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:54:59 by suchua            #+#    #+#             */
/*   Updated: 2022/12/12 19:54:59 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(char c, t_win *win, int x, int y)
{
	// mlx_put_image_to_window(win->mlx, win->win, win->bg, x, y);
	// if (c == '1')
	// 	mlx_put_image_to_window(win->mlx, win->win, win->map->w_img, x, y);
	// if (c == '0')
	// 	mlx_put_image_to_window(win->mlx, win->win, win->map->empty_img, x, y);
	if (c == 'C')
		mlx_put_image_to_window(win->mlx, win->win, win->map->c_img, x, y);
	// if (c == 'E')
	// {
	// 	mlx_put_image_to_window(win->mlx, win->win, win->map->ex_img, x, y);
	// 	win->map->ex_pos.x = x;
	// 	win->map->ex_pos.y = y;
	// }
	if (c == 'P')
		mlx_put_image_to_window(win->mlx, win->win, win->player->p_img, x, y);
}

void	put_score(t_win *win)
{
	char	*sc;

	sc = ft_itoa(win->player->score);
	mlx_string_put(win->mlx, win->win, 20, 20, 0xFFFFFF, sc);
	free(sc);
}

void	render_map(t_win *win)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	y = 0;
	while (win->map->mapping[++i])
	{
		j = -1;
		x = 0;
		while (win->map->mapping[i][++j])
		{
			put_img(win->map->mapping[i][j], win, x, y);
			put_score(win);
			x += 64;
		}
		y += 64;
	}
}
