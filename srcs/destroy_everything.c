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

void	destroy_enemy(t_enemy *lst)
{
	t_enemy	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	destroy_img(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img->empty_img);
	mlx_destroy_image(win->mlx, win->img->w_img);
	mlx_destroy_image(win->mlx, win->img->c_img);
	mlx_destroy_image(win->mlx, win->img->anim->pl1);
	mlx_destroy_image(win->mlx, win->img->anim->pl2);
	mlx_destroy_image(win->mlx, win->img->anim->pr1);
	mlx_destroy_image(win->mlx, win->img->anim->pr2);
	mlx_destroy_image(win->mlx, win->img->anim->ex_img);
	mlx_destroy_image(win->mlx, win->img->anim->ex_open_img);
	mlx_destroy_image(win->mlx, win->img->anim->demon_left);
	mlx_destroy_image(win->mlx, win->img->anim->demon_right);
	free(win->img->anim);
	free(win->img);
}

void	destroy_everything(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	destroy_map(win);
	destroy_img(win);
	destroy_enemy(win->enemy);
	free(win->player);
}
