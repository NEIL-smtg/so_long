/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 04:16:56 by suchua            #+#    #+#             */
/*   Updated: 2022/12/12 04:16:56 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->mapping[++i])
		free(map->mapping[i]);
	free(map->mapping);
	free(map);
	exit(EXIT_FAILURE);
}

void	check_len(t_map *map)
{
	int	i;

	i = 0;
	while (map->mapping[++i])
	{
		if (ft_strlen(map->mapping[i]) != map->w)
		{
			ft_printf("Invalid map! (length)\n");
			free_map(map);
		}
	}
}

void	check_collectible_exit(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->c = 0;
	map->e = 0;
	while (map->mapping[++i])
	{
		j = -1;
		while (map->mapping[i][++j])
		{
			if (map->mapping[i][j] == 'C')
				map->c++;
			else if (map->mapping[i][j] == 'E')
				map->e++;
		}
	}
	if (map->c < 1 || map->e < 1)
	{
		ft_printf("Invalid map! (Collectible < 0)\n");
		free(map);
	}
}

void	check_start_pos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->p = 0;
	while (map->mapping[++i])
	{
		j = -1;
		while (map->mapping[i][++j])
			if (map->mapping[i][j] == 'P')
				map->p++;
	}
	if (map->p != 1)
	{
		ft_printf("Invalid map! (pos < 1 || pos > 1)\n");
		free(map);
	}
}

void	check_invalid_ch(t_map *map)
{
	int		i;
	int		j;
	char	ch;

	map->empty = 0;
	map->wall = 0;
	i = -1;
	while (map->mapping[++i])
	{
		j = -1;
		while (map->mapping[i][++j])
		{
			ch = map->mapping[i][j];
			if (ch != '0' && ch != '1' && ch != 'C' && ch != 'E' && ch != 'P')
			{
				ft_printf("Wrong map input \"%c\"\n", ch);
				free_map(map);
			}
			if (ch == '0')
				map->empty++;
			if (ch == '1')
				map->wall++;
		}
	}
}
