/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_tracker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:15:50 by suchua            #+#    #+#             */
/*   Updated: 2022/12/26 14:15:50 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	track_left(t_player *p, t_map *map, char c)
{
	int	dx;
	int	dy;
	int	i;

	dx = p->p_x - 16;
	dy = p->p_y;
	i = 0;
	while (i < 4)
	{
		if (map->mapping[dy / 64][dx / 64] == c)
			return (1);
		++i;
		if (i == 1)
			dy += 48;
		if (i == 2)
			dx += 48;
		if (i == 3)
			dy -= 48;
	}
	return (0);
}

int	track_right(t_player *p, t_map *map, char c)
{
	int	dx;
	int	dy;
	int	i;

	dx = p->p_x + 16;
	dy = p->p_y;
	i = 0;
	while (i < 4)
	{
		if (map->mapping[dy / 64][dx / 64] == c)
			return (1);
		++i;
		if (i == 1)
			dy += 48;
		if (i == 2)
			dx += 48;
		if (i == 3)
			dy -= 48;
	}
	return (0);
}

int	track_up(t_player *p, t_map *map, char c)
{
	int	dx;
	int	dy;
	int	i;

	dx = p->p_x;
	dy = p->p_y - 16;
	i = 0;
	while (i < 4)
	{
		if (map->mapping[dy / 64][dx / 64] == c)
			return (1);
		++i;
		if (i == 1)
			dy += 48;
		if (i == 2)
			dx += 48;
		if (i == 3)
			dy -= 48;
	}
	return (0);
}

int	track_down(t_player *p, t_map *map, char c)
{
	int	dx;
	int	dy;
	int	i;

	dx = p->p_x;
	dy = p->p_y + 16;
	i = 0;
	while (i < 4)
	{
		if (map->mapping[dy / 64][dx / 64] == c)
			return (1);
		++i;
		if (i == 1)
			dy += 48;
		if (i == 2)
			dx += 48;
		if (i == 3)
			dy -= 48;
	}
	return (0);
}

int	movement_tracker(t_win *win, int dir_type, int w_type)
{
	char	c;

	if (w_type == WALL)
		c = '1';
	if (w_type == COIN)
		c = 'C';
	if (w_type == EX)
		c = 'E';
	if (dir_type == LEFT)
		return (track_left(win->player, win->map, c));
	if (dir_type == RIGHT)
		return (track_right(win->player, win->map, c));
	if (dir_type == UP)
		return (track_up(win->player, win->map, c));
	if (dir_type == DOWN)
		return (track_down(win->player, win->map, c));
}
