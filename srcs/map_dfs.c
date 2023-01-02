/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:08:17 by suchua            #+#    #+#             */
/*   Updated: 2022/12/22 17:08:17 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs_c(int i, int j, t_map *map, int *a)
{
	if (map->v->c != *a)
		return ;
	if (i < 1 || i > (map->h - 2) || j < 1 || j > (map->w - 2))
		return ;
	if (map->v->vis[i][j])
		return ;
	if (map->mapping[i][j] == '1')
		return ;
	if (map->mapping[i][j] == 'P')
	{
		++(*a);
		return ;
	}
	map->v->vis[i][j] = 1;
	dfs_c(i - 1, j, map, a);
	dfs_c(i + 1, j, map, a);
	dfs_c(i, j - 1, map, a);
	dfs_c(i, j + 1, map, a);
}

void	dfs_e(int i, int j, t_map *map, int *a2)
{
	if (*a2 > 0)
		return ;
	if (i < 1 || i > (map->h - 2) || j < 1 || j > (map->w - 2))
		return ;
	if (map->v->vis[i][j] || map->mapping[i][j] == '1')
		return ;
	if (map->mapping[i][j] == 'P')
	{
		++(*a2);
		return ;
	}
	map->v->vis[i][j] = 1;
	dfs_e(i + 1, j, map, a2);
	dfs_e(i - 1, j, map, a2);
	dfs_e(i, j + 1, map, a2);
	dfs_e(i, j - 1, map, a2);
}

//utils
void	free_vis(t_vis *v, int h)
{
	int	i;

	i = -1;
	while (++i < h)
		free(v->vis[i]);
	free(v->vis);
	free(v);
}

void	clear_vis(t_vis *v, int h, int w)
{
	int	i;
	int	j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
			v->vis[i][j] = 0;
	}
}
