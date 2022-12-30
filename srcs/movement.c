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
	mlx_clear_window(win->mlx, win->win);
	render_map(win);
	win->player->is_moving = 0;
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
	mlx_clear_window(win->mlx, win->win);
	render_map(win);
	win->player->is_moving = 0;
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
	win->img->p_img = win->img->anim->pl1;
	mlx_clear_window(win->mlx, win->win);
	render_map(win);
	win->player->is_moving = 0;
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
	win->img->p_img = win->img->anim->pr1;
	mlx_clear_window(win->mlx, win->win);
	render_map(win);
	win->player->is_moving = 0;
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
// 	if (keycode == 13)
// 		move_up(win);
// 	else if (keycode == 1)
// 		move_down(win);
// 	else if (keycode == 0)
// 		move_left(win);
// 	else if (keycode == 2)
// 		move_right(win);
// 	return (0);
// }

// void	move_up(t_win *win)
// {
// 	t_player	*p;
// 	int			nx;
// 	int			ny;

// 	p = win->player;
// 	nx = p->p_x / 64;
// 	ny = (p->p_y - 16) / 64;
// 	if (movement_tracker(win, UP, WALL))
// 		return ;
// 	if (movement_tracker(win, UP, COIN))
// 		handle_score(win, ny, nx);
// 	if (movement_tracker(win, UP, EX))
// 		game_over(win);
// 	p->p_y -= 16;
// 	p->steps++;
// 	mlx_clear_window(win->mlx, win->win);
// 	render_map(win);
// 	mlx_put_image_to_window(win->mlx, win->win,
// 		win->img->p_img, p->p_x, p->p_y);
// }

// void	move_down(t_win *win)
// {
// 	t_player	*p;
// 	int			nx;
// 	int			ny;

// 	p = win->player;
// 	nx = p->p_x / 64;
// 	ny = (p->p_y + 64) / 64;
// 	if (movement_tracker(win, DOWN, WALL))
// 		return ;
// 	if (movement_tracker(win, DOWN, COIN))
// 		handle_score(win, ny, nx);
// 	if (movement_tracker(win, DOWN, EX))
// 		game_over(win);
// 	p->p_y += 16;
// 	p->steps++;
// 	mlx_clear_window(win->mlx, win->win);
// 	render_map(win);
// 	mlx_put_image_to_window(win->mlx, win->win,
// 		win->img->p_img, p->p_x, p->p_y);
// }

// void	move_left(t_win *win)
// {
// 	t_player	*p;
// 	int			nx;
// 	int			ny;

// 	p = win->player;
// 	nx = (p->p_x - 16) / 64;
// 	ny = p->p_y / 64;
// 	if (movement_tracker(win, LEFT, WALL))
// 		return ;
// 	if (movement_tracker(win, LEFT, COIN))
// 		handle_score(win, ny, nx);
// 	if (movement_tracker(win, LEFT, EX))
// 		game_over(win);
// 	p->p_x -= 16;
// 	p->steps++;
// 	mlx_clear_window(win->mlx, win->win);
// 	render_map(win);
// 	get_player_left_pic(win);
// 	mlx_put_image_to_window(win->mlx, win->win,
// 		win->img->p_img, p->p_x, p->p_y);
// }

// void	move_right(t_win *win)
// {
// 	t_player	*p;
// 	int			nx;
// 	int			ny;

// 	p = win->player;
// 	nx = (p->p_x + 64) / 64;
// 	ny = p->p_y / 64;
// 	if (movement_tracker(win, RIGHT, WALL))
// 		return ;
// 	if (movement_tracker(win, RIGHT, COIN))
// 		handle_score(win, ny, nx);
// 	if (movement_tracker(win, RIGHT, EX))
// 		game_over(win);
// 	p->p_x += 16;
// 	p->steps++;
// 	mlx_clear_window(win->mlx, win->win);
// 	render_map(win);
// 	get_player_right_pic(win);
// 	mlx_put_image_to_window(win->mlx, win->win,
// 		win->img->p_img, p->p_x, p->p_y);
// }
