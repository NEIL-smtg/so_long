/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:31:47 by suchua            #+#    #+#             */
/*   Updated: 2023/01/02 12:22:41 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_enemy(t_win *win)
{
	t_enemy	*lst;

	lst = win->enemy;
	while (lst)
	{
		mlx_put_image_to_window(win->mlx, win->win, lst->img,
			lst->j * 64, lst->i * 64);
		lst = lst->next;
	}
}

int	get_enemy_size(t_enemy *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

t_enemy	*get_last_elem(t_enemy *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_enemy_to_list(t_win *win, int i, int j)
{
	t_enemy	*new;
	t_enemy	*last;

	new = ft_calloc(1, sizeof(t_enemy));
	new->i = i;
	new->j = j;
	new->next = NULL;
	new->img = win->img->anim->demon_r1;
	new->direction = RIGHT;
	if (!win->enemy)
	{
		win->enemy = new;
		return ;
	}
	last = get_last_elem(win->enemy);
	last->next = new;
}
