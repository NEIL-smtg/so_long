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

void	prompt_error(int fd, char *line)
{
	ft_printf("Map Error!\n");
	close(fd);
	if (!line)
		free(line);
	exit(EXIT_FAILURE);
}

void	init_mp_status(map_status *mp_s)
{
	mp_s->collectibles = 0;
	mp_s->empty = 0;
	mp_s->exit = 0;
	mp_s->pos = 0;
	mp_s->wall = 0;
	mp_s->len = 0;
}

int	check_mp_line(char *line, map_status *mp_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '0')
			mp_s->empty++;
		else if (line[i] == '1')
			mp_s->wall++;
		else if (line[i] == 'C')
			mp_s->collectibles++;
		else if (line[i] == 'E')
			mp_s->exit++;
		else if (line[i] == 'P')
			mp_s->pos++;
		else
			break ;
		++i;
	}
	if (line[i] == 0)
		return (1);
	else if (line[i + 1] == '\n' || line[i + 1] == 0)
		return (1);
	return (0);
}

int	check_line_size(int *len, char *line)
{
	int	size;

	size = ft_strlen(line);
	if (line[size - 1] == '\n')
		size--;
	if (*len != size)
		return (0);
	*len = size;
	return (1);
}

void	check_map(char *mp)
{
	int			fd;
	char		*line;
	map_status	mp_s;

	fd = open(mp, O_RDONLY);
	init_mp_status(&mp_s);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] != '\n')
			mp_s.len = ft_strlen(line);
		if (mp_s.len != 0)
			if (mp_s.len != ft_strlen(line))
				prompt_error(fd, line);
		if (!check_mp_line(line, &mp_s))
			prompt_error(fd, line);
		mp_s.len = ft_strlen(line);
		free(line);
	}
	close(fd);
	if (!mp_s.collectibles || !mp_s.exit || !mp_s.pos)
		prompt_error(fd, NULL);
}

void	ft_parse_map(int ac, char **av)
{
	char	*map;

	if (ac == 2)
	{
		map = av[1];
		if (ft_strncmp(map, "map", 3) != 0 || map[4])
		{
			ft_printf("Wrong Map Argument!\n");
			exit(EXIT_FAILURE);
		}
		if (map[3] == '2')
			check_map("maps/map2.ber");
		else if (map[3] == '3')
			check_map("maps/map3.ber");
		else if (map[3] == '4')
			check_map("maps/map4.ber");
		else
			check_map("maps/map1.ber");
	}
	else
		check_map("maps/map1.ber");
}
