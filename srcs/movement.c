/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:42:29 by suchua            #+#    #+#             */
/*   Updated: 2022/12/15 23:42:29 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// linux
int	key_on_pressed(int keycode, t_win *win)
{
	if (keycode == 65307)
	{
		destroy_everything(win);
		exit(EXIT_FAILURE);
	}
	if (keycode == 'w')
		move_up(win);
	if (keycode == 's')
		move_down(win);
	if (keycode == 'a')
		move_left(win);
	if (keycode == 'd')
		move_right(win);
	return (0);
}

// //mac
// int	key_on_pressed(int keycode, t_win *win)
// {
// 	if (keycode == 53)
// 	{
// 		destroy_everything(win);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (keycode == 13)
// 		move_up(win);
// 	if (keycode == 1)
// 		move_down(win);
// 	if (keycode == 0)
// 		move_left(win);
// 	if (keycode == 2)
// 		move_right(win);
// 	return (0);
// }

void	move_up(t_win *win)
{
	int	x;
	int	y;

	x = win->player->p_x;
	y = win->player->p_y;
	if ((y - 1) > 0 && win->map->mapping[y - 1][x] != '1')
	{
		if (win->map->mapping[y - 1][x] == 'C')
			handle_score(win);
		if (win->map->mapping[y - 1][x] == 'E' && !game_over(win))
			return ;
		win->map->mapping[y][x] = '0';
		win->map->mapping[y - 1][x] = 'P';
		update_pos_and_render(win, UP);
	}
}

void	move_down(t_win *win)
{
	int	x;
	int	y;

	x = win->player->p_x;
	y = win->player->p_y;
	if ((y + 1) < win->map->h && win->map->mapping[y + 1][x] != '1')
	{
		if (win->map->mapping[y + 1][x] == 'C')
			handle_score(win);
		if (win->map->mapping[y + 1][x] == 'E' && !game_over(win))
			return ;
		win->map->mapping[y][x] = '0';
		win->map->mapping[y + 1][x] = 'P';
		update_pos_and_render(win, DOWN);
	}
}

void	move_left(t_win *win)
{
	int	x;
	int	y;

	x = win->player->p_x;
	y = win->player->p_y;
	if ((x - 1) > 0 && win->map->mapping[y][x - 1] != '1')
	{
		if (win->map->mapping[y][x - 1] == 'C')
			handle_score(win);
		if (win->map->mapping[y][x - 1] == 'E' && !game_over(win))
			return ;
		win->map->mapping[y][x] = '0';
		win->map->mapping[y][x - 1] = 'P';
		update_pos_and_render(win, LEFT);
	}
}

void	move_right(t_win *win)
{
	int	x;
	int	y;

	x = win->player->p_x;
	y = win->player->p_y;
	if ((x + 1) < win->map->w && win->map->mapping[y][x + 1] != '1')
	{
		if (win->map->mapping[y][x + 1] == 'C')
			handle_score(win);
		if (win->map->mapping[y][x + 1] == 'E' && !game_over(win))
			return ;
		win->map->mapping[y][x] = '0';
		win->map->mapping[y][x + 1] = 'P';
		update_pos_and_render(win, RIGHT);
	}
}
