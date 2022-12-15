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

int	key_on_pressed(int keycode, t_win *win)
{
	ft_printf("here\n");
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

void	move_up(t_win *win)
{
	int	x;
	int	y;

	x = win->player->p_x;
	y = win->player->p_y;
	if ((y - 1) > 0 && win->map->mapping[y - 1][x] != '1')
	{
		win->map->mapping[y][x] = '0';
		win->map->mapping[y - 1][x] = 'P';
		get_player_pos(win);
		mlx_clear_window(win->mlx, win->win);
		render_map(win);
		ft_printf("up\n");
	}
}

void	move_down(t_win *win)
{
	int	x;
	int	y;

	x = win->player->p_x;
	y = win->player->p_y;
	if (win->map->mapping[y + 1][x] != '1')
	{
		win->map->mapping[y][x] = '0';
		win->map->mapping[y + 1][x] = 'P';
		get_player_pos(win);
		mlx_clear_window(win->mlx, win->win);
		render_map(win);
	}
}

void	move_left(t_win *win)
{
	int	x;
	int	y;

	x = win->player->p_x;
	y = win->player->p_y;
	if (win->map->mapping[y][x - 1] != '1')
	{
		win->map->mapping[y][x] = '0';
		win->map->mapping[y][x - 1] = 'P';
		get_player_pos(win);
		mlx_clear_window(win->mlx, win->win);
		render_map(win);
	}
}

void	move_right(t_win *win)
{
	int	x;
	int	y;

	x = win->player->p_x;
	y = win->player->p_y;
	if (win->map->mapping[y][x + 1] != '1')
	{
		win->map->mapping[y][x] = '0';
		win->map->mapping[y][x + 1] = 'P';
		get_player_pos(win);
		mlx_clear_window(win->mlx, win->win);
		render_map(win);
	}
}