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

void	free_vis(t_vis *v, int h)
{
	int	i;

	i = -1;
	while (++i < h)
		free(v->vis[i]);
	free(v->vis);
	free(v);
}

void	dfs_c(int i, int j, t_map *map, int *a)
{
	if (i < 1 || i > (map->h - 2) || j < 1 || j > (map->w - 2))
		return ;
	if (map->v->vis[i][j])
		return ;
	if (map->mapping[i][j] == '1' || map->mapping[i][j] == 'E')
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

void	is_there_a_path(t_win *win)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	i = -1;
	win->map->v = ft_calloc(1, sizeof(t_vis));
	win->map->v->vis = ft_calloc(win->map->h, sizeof(int *));
	while (++i < win->map->h)
		win->map->v->vis[i] = ft_calloc(win->map->w, sizeof(int));
	i = -1;
	while (++i < win->map->h)
	{
		j = -1;
		while (++j < win->map->w)
		{
			if (win->map->mapping[i][j] == 'C')
			{
				clear_vis(win->map->v, win->map->h, win->map->w);
				dfs_c(i, j, win->map, &a);
			}
		}
	}
	ft_printf("%d %d\n", a, win->map->c);
	free_vis(win->map->v, win->map->h);
	if (a >= win->map->c)
		return ;
	ft_printf("Error !!\nThere is no path to win !!\n");
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
