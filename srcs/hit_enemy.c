/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:28:57 by suchua            #+#    #+#             */
/*   Updated: 2022/12/30 21:28:57 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_pos(t_enemy **lst, t_player **p, char **mp)
{
	t_enemy	*l;
	int		i;
	int		j;

	l = (*lst);
	(*p)->p_i = (*p)->ori_pi;
	(*p)->p_j = (*p)->ori_pj;
	i = -1;
	while (mp[++i])
	{
		j = -1;
		while (mp[i][++j])
		{
			if (mp[i][j] == 'N')
			{
				l->i = i;
				l->j = j;
				l = l->next;
				if (!l)
					return ;
			}
		}
	}
}

void	hit_enemy(t_win *win, int i, int j)
{
	t_enemy	*lst;

	lst = win->enemy;
	while (lst)
	{
		if (lst->i == i && lst->j == j)
		{
			win->player->lives--;
			health_bar_animation(win->player->lives, win->img->anim, win->img);
			if (win->player->lives == 0)
			{
				ft_printf("You are dead !!!!\n");
				return ;
			}
			win->pause = 1;
			reset_pos(&win->enemy, &win->player, win->map->mapping);
			mlx_clear_window(win->mlx, win->win);
			render_map(win);
			return ;
		}
		lst = lst->next;
	}
}
