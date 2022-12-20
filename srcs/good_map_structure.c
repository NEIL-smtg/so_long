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
