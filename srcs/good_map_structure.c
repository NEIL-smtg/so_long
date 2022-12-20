/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_map_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:11:44 by suchua            #+#    #+#             */
/*   Updated: 2022/12/12 19:11:44 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs_player(int i, int j, t_map *map, int *a)
{
	if (i < 0 || i > (map->h - 1) || j < 0 || j > (map->w - 1) || *a > 0)
		return ;
	if (map->mapping[i][j] == '1')
		return ;
	if (map->mapping[i][j] == 'E')
	{
		++(*a);
		return ;
	}
	dfs_player(i - 1, j, map, a);
	dfs_player(i + 1, j, map, a);
	dfs_player(i, j - 1, map, a);
	dfs_player(i, j + 1, map, a);
}

void	dfs_c(int i, int j, t_map *map, int *a)
{
	if (i < 0 || i > (map->h - 1) || j < 0 || j > (map->w - 1))
		return ;
	if (map->mapping[i][j] == '1')
		return ;
	if (map->mapping[i][j] == 'P')
	{
		++(*a);
		return ;
	}
	if (*a == map->c)
		return ;
	dfs_c(i + 1, j, map, a);
	dfs_c(i - 1, j, map, a);
	dfs_c(i, j - 1, map, a);
	dfs_c(i, j + 1, map, a);
}

void	is_there_a_path(t_win *win)
{
	int	i;
	int	j;
	int	a;
	int	a2;

	i = -1;
	a = 0;
	a2 = 0;
	while (win->map->mapping[++i])
	{
		j = -1;
		while (win->map->mapping[i][++j])
		{
			if (win->map->mapping[i][j] == 'P')
				dfs_player(i, j, win->map, &a);
			if (win->map->mapping[i][j] == 'C')
				dfs_c(i, j, win->map, &a2);
		}
	}
	if (a2 != win->map->c || a < 1)
		free_map_exit(win->map);
}

//check if map is surrounded by walls
void	good_map_structure(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->w)
	{
		if (map->mapping[0][i] != '1' || map->mapping[map->h - 1][i] != '1')
		{
			ft_printf("ERROR !!!\n");
			ft_printf("Wrong map structure! (WALL) :: column : %d\n", i);
			free_map_exit(map);
		}
	}
	i = -1;
	while (++i < map->h)
	{
		if (map->mapping[i][0] != '1' || map->mapping[i][map->w - 1] != '1')
		{
			ft_printf("ERROR !!!\nWrong map structure! (WALL) :: Line : %d\n", i);
			free_map_exit(map);
		}
	}
}
