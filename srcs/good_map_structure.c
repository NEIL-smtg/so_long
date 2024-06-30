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

void	get_new_vis(t_win *win, int a)
{
	int	i;

	i = -1;
	win->map->v = ft_calloc(1, sizeof(t_vis));
	win->map->v->vis = ft_calloc(win->map->h, sizeof(int *));
	win->map->v->c = a;
	while (++i < win->map->h)
		win->map->v->vis[i] = ft_calloc(win->map->w, sizeof(int));
}

void	before_dfs_c(int i, int j, t_map *map, int *a)
{
	clear_vis(map->v, map->h, map->w);
	dfs_c(i, j, map, a);
	map->v->c = *a;
}

void	before_dfs_e(int i, int j, t_map *map, int *a2)
{
	*a2 = 0;
	clear_vis(map->v, map->h, map->w);
	dfs_e(i, j, map, a2);
}

void	is_there_a_path(t_win *win)
{
	int		i;
	int		j;
	int		a;
	int		a2;

	a = 0;
	i = -1;
	get_new_vis(win, a);
	while (++i < win->map->h)
	{
		j = -1;
		while (++j < win->map->w)
		{
			if (win->map->mapping[i][j] == 'C')
				before_dfs_c(i, j, win->map, &a);
			if (win->map->mapping[i][j] == 'E')
				before_dfs_e(i, j, win->map, &a2);
		}
	}
	free_vis(win->map->v, win->map->h);
	if (a == win->map->c && a2 > 0)
		return ;
	ft_putstr_fd("Error !!\nThere is no path to win !!\n", 2);
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
			ft_printf("ERROR !!!\n");
			ft_printf("Map structure! (WALL) :: Line : %d\n", i);
			free_map_exit(map);
		}
	}
}
