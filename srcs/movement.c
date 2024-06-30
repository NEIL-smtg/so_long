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

void	move_up(t_win *win)
{
	int	ni;
	int	nj;

	ni = win->player->p_i - 1;
	nj = win->player->p_j;
	hit_enemy(win, ni, nj);
	if (win->map->mapping[ni][nj] == '1')
		return ;
	if (win->map->mapping[ni][nj] == 'C')
	{
		win->player->score++;
		win->map->c--;
		win->map->mapping[ni][nj] = '0';
	}
	if (win->map->mapping[ni][nj] == 'E')
		game_over(win);
	win->player->p_i--;
	win->player->steps++;
	print_step(ft_itoa(win->player->steps));
	if (!win->map->c)
		win->img->ex_img = win->img->anim->ex_open_img;
	refresh_screen(win);
}

void	move_down(t_win *win)
{
	int	ni;
	int	nj;

	ni = win->player->p_i + 1;
	nj = win->player->p_j;
	hit_enemy(win, ni, nj);
	if (win->map->mapping[ni][nj] == '1')
		return ;
	if (win->map->mapping[ni][nj] == 'C')
	{
		win->player->score++;
		win->map->c--;
		win->map->mapping[ni][nj] = '0';
	}
	if (win->map->mapping[ni][nj] == 'E')
		game_over(win);
	win->player->p_i++;
	win->player->steps++;
	print_step(ft_itoa(win->player->steps));
	if (!win->map->c)
		win->img->ex_img = win->img->anim->ex_open_img;
	refresh_screen(win);
}

void	move_left(t_win *win)
{
	int	ni;
	int	nj;

	ni = win->player->p_i;
	nj = win->player->p_j - 1;
	hit_enemy(win, ni, nj);
	if (win->map->mapping[ni][nj] == '1')
		return ;
	if (win->map->mapping[ni][nj] == 'C')
	{
		win->player->score++;
		win->map->c--;
		win->map->mapping[ni][nj] = '0';
	}
	if (win->map->mapping[ni][nj] == 'E')
		game_over(win);
	win->player->p_j--;
	win->player->steps++;
	print_step(ft_itoa(win->player->steps));
	if (!win->map->c)
		win->img->ex_img = win->img->anim->ex_open_img;
	player_animation_transition(win->img, win->img->anim, LEFT);
	refresh_screen(win);
}

void	move_right(t_win *win)
{
	int	ni;
	int	nj;

	ni = win->player->p_i;
	nj = win->player->p_j + 1;
	hit_enemy(win, ni, nj);
	if (win->map->mapping[ni][nj] == '1')
		return ;
	if (win->map->mapping[ni][nj] == 'C')
	{
		win->player->score++;
		win->map->c--;
		win->map->mapping[ni][nj] = '0';
	}
	if (win->map->mapping[ni][nj] == 'E')
		game_over(win);
	win->player->p_j++;
	win->player->steps++;
	print_step(ft_itoa(win->player->steps));
	if (!win->map->c)
		win->img->ex_img = win->img->anim->ex_open_img;
	player_animation_transition(win->img, win->img->anim, RIGHT);
	refresh_screen(win);
}

int	key_on_pressed(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
	{
		destroy_everything(win);
		exit(EXIT_FAILURE);
	}
	if (win->player->lives <= 0)
	{
		ft_printf("You are dead !!!!\n");
		return (0);
	}
	if (win->pause)
		return (0);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		win->player->is_moving = 1;
	if (keycode == KEY_W)
		move_up(win);
	else if (keycode == KEY_S)
		move_down(win);
	else if (keycode == KEY_A)
		move_left(win);
	else if (keycode == KEY_D)
		move_right(win);
	return (0);
}
