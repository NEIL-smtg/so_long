/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:48:43 by suchua            #+#    #+#             */
/*   Updated: 2022/12/09 13:48:43 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_path(char *path)
{
	int	map_fd;

	map_fd = open(path, O_RDONLY);
	if (map_fd <= 0)
	{
		ft_printf("Wrong path !\n");
		close(map_fd);
		exit(EXIT_FAILURE);
	}
	close(map_fd);
}

void	init_map(t_map *map)
{
	int	h;

	h = -1;
	while (map->mapping[++h])
		map->h = h + 1;
	map->w = ft_strlen(map->mapping[0]);
	map->empty = 0;
	map->wall = 0;
	map->n = 0;
	map->p = 0;
	map->c = 0;
	map->e = 0;
}

void	valid_map(t_win *win)
{
	check_len(win->map);
	if (win->map->w == win->map->h)
	{
		ft_printf("Error !!\nMap has to be in rectangle shape !!\n");
		free_map_exit(win->map);
	}
	check_collectible_exit(win->map);
	check_start_pos(win->map);
	check_invalid_ch(win->map);
	good_map_structure(win->map);
	is_there_a_path(win);
}

void	free_liness_exit(char *line1, char *line2)
{
	free(line1);
	free(line2);
	ft_printf("Error !!!\nEmpty line !\n");
	exit(EXIT_FAILURE);
}

void	get_map(char *path, t_win *win)
{
	int		fd;
	char	*partial;
	char	*whole;

	fd = open(path, O_RDONLY);
	whole = ft_calloc(1, sizeof(char));
	while (1)
	{
		partial = get_next_line(fd);
		if (!partial)
			break ;
		if (partial[ft_strlen(partial) - 2] == 13)
			partial[ft_strlen(partial) - 2] = 10;
		if (*partial == 10)
			free_liness_exit(whole, partial);
		whole = gnl_strjoin(whole, partial);
		free(partial);
	}
	win->map = ft_calloc(1, sizeof(t_map));
	win->map->mapping = ft_split(whole, '\n');
	free(whole);
	init_map(win->map);
	valid_map(win);
}
