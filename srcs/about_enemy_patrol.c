/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_enemy_patrol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:20:30 by suchua            #+#    #+#             */
/*   Updated: 2022/12/24 17:20:30 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	enemy_patrol(t_win *win)
{
	t_enemy	*lst;

	lst = win->enemy;
	while (lst)
	{
		hit_enemy(win, win->player->p_i, win->player->p_j);
		lst = lst->next;
	}
}
