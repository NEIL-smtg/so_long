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
	if (!win->map->c)
		win->img->ex_img = win->img->anim->ex_open_img;
	if (win->img->p_img == win->img->anim->pr1)
		win->img->p_img = win->img->anim->pl1;
	else
		win->img->p_img = win->img->anim->pl2;
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
	if (!win->map->c)
		win->img->ex_img = win->img->anim->ex_open_img;
	if (win->img->p_img == win->img->anim->pl1)
		win->img->p_img = win->img->anim->pr1;
	else
		win->img->p_img = win->img->anim->pr2;
	refresh_screen(win);
}

// linux
int	key_on_pressed(int keycode, t_win *win)
{
	if (keycode == 65307)
	{
		destroy_everything(win);
		exit(EXIT_FAILURE);
	}
	if (win->player->lives == 0)
	{
		ft_putstr_fd("You are dead !!\n", 1);
		return (0);
	}
	if (win->pause)
		return (0);
	if (keycode == 'w' || keycode == 's' || keycode == 'a' || keycode == 'd')
		win->player->is_moving = 1;
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

//mac
// int	key_on_pressed(int keycode, t_win *win)
// {
// 	if (keycode == 53)
// 	{
// 		destroy_everything(win);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (win->player->lives == 0)
// 	{
// 		ft_printf("You are dead !!!!\n");
// 		return (0);
// 	}
// 	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
// 		win->player->is_moving = 1;
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
