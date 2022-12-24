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

int	enemy_patrol(t_win *win)
{
	t_enemy	*lst;
	char	**mp;

	if (!win->enemy)
		return (0);
	mp = win->map->mapping;
	lst = win->enemy;
	while (lst)
	{
		if (mp[lst->i][lst->j + 1] != '1')
			++lst->j;
		else
			--lst->j;
		lst = lst->next;
	}
	return (0);
}
