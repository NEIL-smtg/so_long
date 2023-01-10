/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:23:22 by suchua            #+#    #+#             */
/*   Updated: 2022/12/28 18:23:22 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walking(t_win *win)
{
	t_img	*i;
	t_anim	*an;

	if (!win->player->is_moving)
		return ;
	i = win->img;
	an = win->img->anim;
	if (i->p_img == an->pr1)
		i->p_img = an->pr2;
	else if (i->p_img == an->pr2)
		i->p_img = an->pr1;
	else if (i->p_img == an->pl1)
		i->p_img = an->pl2;
	else if (i->p_img == an->pl2)
		i->p_img = an->pl1;
}

void	enemy_animation(t_enemy *lst, t_anim *a)
{
	while (lst)
	{
		if (lst->img == a->demon_r1)
			lst->img = a->demon_r2;
		else if (lst->img == a->demon_r2)
			lst->img = a->demon_r3;
		else
			lst->img = a->demon_r1;
		lst = lst->next;
	}
}

void	health_bar_animation(int lives, t_anim *a, t_img *i)
{
	if (lives == 2)
		i->health_bar = a->lives_half;
	if (lives == 1)
		i->health_bar = a->lives_low;
	if (lives == 0)
		i->health_bar = a->lives_dead;
}

int	stop_animation(int keycode, t_win *win)
{
	if (win->player->is_moving)
		win->player->is_moving = 0;
	return (0);
}

int	animation(t_win *win)
{
	if (win->player->lives <= 0)
		return (0);
	win->frame++;
	if (win->pause)
	{
		spawn_player_animation(win);
		return (0);
	}
	if (win->frame != 8000)
		return (0);
	player_idle(win->player->is_moving, win->img, win->img->anim);
	walking(win);
	enemy_animation(win->enemy, win->img->anim);
	enemy_patrol(win);
	mlx_clear_window(win->mlx, win->win);
	render_map(win);
	win->frame = 0;
	return (0);
}
