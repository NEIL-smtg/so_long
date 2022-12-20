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

void	set_map_vars(t_map *map)
{
	int	h;

	h = -1;
	while (map->mapping[++h])
		map->h = h + 1;
	map->w = ft_strlen(map->mapping[0]);
}

void	valid_map(t_map *map)
{
	check_len(map);
	check_collectible_exit(map);
	check_start_pos(map);
	check_invalid_ch(map);
	good_map_structure(map);
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
	set_map_vars(win->map);
	valid_map(win->map);
}
