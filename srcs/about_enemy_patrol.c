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

void	next_move(t_enemy **node, char **mp)
{
	int	i;
	int	j;
	int	dir;

	i = (*node)->i;
	j = (*node)->j;
	dir = (*node)->direction;
	if (dir != LEFT && mp[i][j + 1] != '1' && mp[i][j + 1] != 'C')
		(*node)->j++;
	else if (dir != LEFT && mp[i + 1][j + 1] != '1' && mp[i + 1][j + 1] != 'C')
	{
		(*node)->i++;
		(*node)->j++;
	}
	else if (dir != RIGHT && mp[i][j - 1] != '1' && mp[i][j + 1] != 'C')
		(*node)->j--;
	else if (dir != RIGHT && mp[i - 1][j - 1] != '1' && mp[i - 1][j - 1] != 'C')
	{
		(*node)->i--;
		(*node)->j--;
	}
	else if (dir != UP && mp[i + 1][j] != '1' && mp[i + 1][j] != 'C')
		(*node)->i++;
	else if (dir != DOWN && mp[i - 1][j] != '1' && mp[i - 1][j] != 'C')
		(*node)->i--;
}

void	enemy_patrol(t_win *win)
{
	t_enemy	*lst;

	lst = win->enemy;
	while (lst)
	{
		// next_move(&lst, win->map->mapping);
		hit_enemy(win, win->player->p_i, win->player->p_j);
		lst = lst->next;
	}
}
