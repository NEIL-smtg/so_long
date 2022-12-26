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
	if (c == '1')
		mlx_put_image_to_window(win->mlx, win->win, win->map->w_img, x, y);
	if (c == '0')
		mlx_put_image_to_window(win->mlx, win->win, win->map->empty_img, x, y);
	if (c == 'C')
	{
		// mlx_put_image_to_window(win->mlx, win->win, win->map->empty_img, x, y);
		mlx_put_image_to_window(win->mlx, win->win, win->map->c_img, x, y);
	}
	if (c == 'E')
	{
		// mlx_put_image_to_window(win->mlx, win->win, win->map->empty_img, x, y);
		mlx_put_image_to_window(win->mlx, win->win, win->map->ex_img, x, y);
	}
	if (c == 'P')
		mlx_put_image_to_window(win->mlx, win->win, win->map->empty_img, x, y);
}

void	put_score_steps(t_win *win)
{
	char	*sc;
	char	*st;

	sc = ft_itoa(win->player->score);
	st = ft_itoa(win->player->steps);
	mlx_string_put(win->mlx, win->win, 10, 10, 0xFFFFFF, sc);
	mlx_string_put(win->mlx, win->win, 10, 30, 0xFFFFFF, st);
	free(sc);
	free(st);
}

void	render_map(t_win *win)
{
	char	**mp;
	int		i;
	int		j;
	int		x;
	int		y;

	mp = win->map->mapping;
	i = -1;
	y = 0;
	while (mp[++i])
	{
		j = -1;
		x = 0;
		while (mp[i][++j])
		{
			put_img(mp[i][j], win, x, y);
			x += 64;
		}
		y += 64;
	}
	put_score_steps(win);
	mlx_put_image_to_window(win->mlx, win->win, win->player->p_img,
		win->player->p_x, win->player->p_y);
	render_enemy(win);
}
