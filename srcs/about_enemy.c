/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:31:47 by suchua            #+#    #+#             */
/*   Updated: 2022/12/25 14:37:02 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_each_enemy(int i, int j, t_win *win)
{
	t_enemy	*list;
	t_enemy	*new;
	int		x;
	int		y;

	list = win->enemy;
	while (win->enemy && list && list->next)
		list = list->next;
	new = ft_calloc(1, sizeof(t_enemy));
	new->i = i;
	new->j = j;
	new->img = mlx_xpm_file_to_image(win->mlx, "xpm/pacman.xpm", &x, &y);
	new->next = NULL;
	if (!list)
		win->enemy = new;
	else
		list->next = new;
}

void	create_enemy_list(int i, int j, t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (win->map->mapping[i - 1][j - 1] == '0')
		create_each_enemy(i - 1, j - 1, win);
	if (win->map->mapping[i - 1][j + 1] == '0')
		create_each_enemy(i - 1, j + 1, win);
	if (win->map->mapping[i + 1][j - 1] == '0')
		create_each_enemy(i + 1, j - 1, win);
	if (win->map->mapping[i + 1][j + 1] == '0')
		create_each_enemy(i + 1, j + 1, win);
}

void	init_enemy(t_win *win)
{
	int	e_i;
	int	e_j;

	e_i = (win->map->h - 1) / 2;
	e_j = (win->map->w - 1) / 2;
	win->enemy = NULL;
	create_enemy_list(e_i, e_j, win);
}

void	render_enemy(t_win *win)
{
	t_enemy	*list;

	if (!win->enemy)
		return ;
	list = win->enemy;
	while (list)
	{
		mlx_put_image_to_window(win->mlx, win->win, list->img,
			list->j * 64, list->i * 64);
		list = list->next;
	}
}
