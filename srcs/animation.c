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

	i = win->img;
	an = win->img->anim;
	if (i->p_img == an->pr1)
		i->p_img = an->pr2;
	else if (i->p_img == an->pr2)
		i->p_img = an->pr1;
	else if (i->p_img == an->pl1)
		i->p_img = an->pl2;
	else
		i->p_img = an->pl1;
}

int	animation(t_win *win)
{
	if (win->player->lives == 0)
		return (0);
	win->frame++;
	if (win->frame != 2000)
		return (0);
	walking(win);
	enemy_patrol(win);
	mlx_clear_window(win->mlx, win->win);
	render_map(win);
	win->frame = 0;
	return (0);
}
