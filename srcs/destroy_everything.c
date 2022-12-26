/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:38:49 by suchua            #+#    #+#             */
/*   Updated: 2022/12/15 23:38:49 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_win *win)
{
	int	i;

	i = -1;
	while (win->map->mapping[++i])
		free(win->map->mapping[i]);
	free(win->map->mapping);
	free(win->map);
}

void	destroy_enemy(t_win *win)
{
	t_enemy	*tmp;
	t_enemy	*ey;

	if (!win->enemy)
		return ;
	ey = win->enemy;
	while (ey)
	{
		tmp = ey->next;
		mlx_destroy_image(win->mlx, ey->img);
		free(ey);
		ey = tmp;
	}
	ey = NULL;
}

void	destroy_img(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img->empty_img);
	mlx_destroy_image(win->mlx, win->img->w_img);
	mlx_destroy_image(win->mlx, win->img->c_img);
	mlx_destroy_image(win->mlx, win->img->ex_img);
	mlx_destroy_image(win->mlx, win->img->p_img);
	free(win->img);
}

void	destroy_everything(t_win *win)
{
	int	i;

	mlx_destroy_window(win->mlx, win->win);
	destroy_map(win);
	destroy_img(win);
	destroy_enemy(win);
	free(win->player);
}
