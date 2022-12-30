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

void	hit_enemy(t_win *win, int i , int j)
{
	t_enemy	*lst;

	lst = win->enemy;
	while (lst)
	{
		if (lst->i == i && lst->j == j)
		{
			win->player->lives--;
			if (win->player->lives == 0)
			{
				ft_printf("You are dead !!!!\n");
				return ;
			}
			get_player_pos(win);
			mlx_clear_window(win->mlx, win->win);
			render_map(win);
			return ;
		}
		lst = lst->next;
	}
}
