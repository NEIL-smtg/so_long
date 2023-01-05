/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:28:57 by suchua            #+#    #+#             */
/*   Updated: 2023/01/04 16:39:15 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation_transition(t_img *img, t_anim *a, int dir)
{
	if (dir == LEFT)
	{
		if (img->p_img == a->pl1 || img->p_img == a->pl2)
			return ;
		if (img->p_img == a->pr2)
			img = a->pl2;
		else
			img->p_img = a->pl1;
	}
	if (dir == RIGHT)
	{
		if (img->p_img == a->pr1 || img->p_img == a->pr2)
			return ;
		if (img->p_img == a->pl2)
			img = a->pr2;
		else
			img->p_img = a->pr1;
	}
}

void	player_idle(int is_moving, t_img *img, t_anim *a)
{
	if (is_moving)
		return ;
	if (img->p_img == a->pr1 || img->p_img == a->pr2)
		img->p_img = a->pr_idle1;
	else if (img->p_img == a->pl1 || img->p_img == a->pl2)
		img->p_img = a->pl_idle1;
	else if (img->p_img == a->pr_idle1)
		img->p_img = a->pr_idle2;
	else if (img->p_img == a->pr_idle2)
		img->p_img = a->pr_idle3;
	else if (img->p_img == a->pr_idle3)
		img->p_img = a->pr_idle1;
	else if (img->p_img == a->pl_idle1)
		img->p_img = a->pl_idle2;
	else if (img->p_img == a->pl_idle2)
		img->p_img = a->pl_idle3;
	else if (img->p_img == a->pl_idle3)
		img->p_img = a->pl_idle1;
}

void	spawn_player_animation(t_win *win)
{
	if (win->frame == 3000 || win->frame == 9000 || win->frame == 15000)
		win->img->p_img = win->img->empty_img;
	else if (win->frame == 6000 || win->frame == 12000)
		win->img->p_img = win->img->anim->pr1;
	else if (win->frame == 18000)
	{
		win->img->p_img = win->img->anim->pr1;
		win->pause = 0;
		win->frame = 0;
	}
	else
		return ;
	mlx_clear_window(win->mlx, win->win);
	render_map(win);
}
