/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:02:35 by suchua            #+#    #+#             */
/*   Updated: 2022/12/28 19:02:35 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_demon_img(t_win *win, int *x, int *y)
{
	win->img->anim->demon_left = mlx_xpm_file_to_image(win->mlx,
			"xpm/demon_left.xpm", x, y);
	win->img->anim->demon_right = mlx_xpm_file_to_image(win->mlx,
			"xpm/demon_right.xpm", x, y);
}

void	init_imgs(t_win *win, int *x, int *y)
{
	win->img = ft_calloc(1, sizeof(t_img));
	win->img->anim = ft_calloc(1, sizeof(t_anim));
	win->img->empty_img = mlx_xpm_file_to_image(win->mlx,
			"xpm/floor2.xpm", x, y);
	win->img->w_img = mlx_xpm_file_to_image(win->mlx,
			"xpm/wall.xpm", x, y);
	win->img->c_img = mlx_xpm_file_to_image(win->mlx,
			"xpm/coin.xpm", x, y);
	win->img->anim->ex_img = mlx_xpm_file_to_image(win->mlx,
			"xpm/door1.xpm", x, y);
	win->img->anim->ex_open_img = mlx_xpm_file_to_image(win->mlx,
			"xpm/exit_open.xpm", x, y);
	win->img->anim->pl1 = mlx_xpm_file_to_image(win->mlx,
			"xpm/pl.xpm", x, y);
	win->img->anim->pr1 = mlx_xpm_file_to_image(win->mlx,
			"xpm/pr.xpm", x, y);
	win->img->anim->pl2 = mlx_xpm_file_to_image(win->mlx,
			"xpm/pl1.xpm", x, y);
	win->img->anim->pr2 = mlx_xpm_file_to_image(win->mlx,
			"xpm/pr1.xpm", x, y);
	init_demon_img(win, x, y);
	win->img->p_img = win->img->anim->pr1;
	win->img->ex_img = win->img->anim->ex_img;
}

void	init(t_win *win, int *x, int *y)
{
	win->win_h = win->map->h * 64;
	win->win_w = win->map->w * 64;
	win->frame = 0;
	win->eframe = 0;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->win_w, win->win_h,
			"SOOOOO FUCKING LOOOOOONG !!!");
	win->player = ft_calloc(1, sizeof(t_player));
	get_player_pos(win);
	win->player->score = 0;
	win->player->lives = 3;
	win->player->steps = 0;
	win->player->is_moving = 0;
	init_imgs(win, x, y);
}
