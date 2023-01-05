/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_enemy_patrol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:20:30 by suchua            #+#    #+#             */
/*   Updated: 2022/12/24 17:20:30 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_enemy(t_enemy **node, int i, int j, t_map *m)
{
	if (i < 1 || i > m->h - 2 || j < 1 || j > m->w - 2)
		return (0);
	// if (m->mapping[i][j] == '1' || m->mapping[i][j] == 'C')
	// 	return (0);
	(*node)->i = i;
	(*node)->j = j;
	return (1);
}

void	enemy_movement(t_win *win, t_enemy **node, int i, int j)
{
	t_player	*p;
	double		a;
	double		b;
	double		c;
	double		d;

	p = win->player;
	a = ft_sqrt((ft_pow((double)(i - 1) - p->p_i, 2))
			+ ft_pow((double)(j - p->p_j), 2)); //UP
	b = ft_sqrt((ft_pow((double)(i + 1) - p->p_i, 2))
			+ ft_pow((double)(j - p->p_j), 2)); //DOWN
	c = ft_sqrt((ft_pow((double)(j - 1) - p->p_j, 2))
			+ ft_pow((double)(i - p->p_i), 2)); //RIGHT
	d = ft_sqrt((ft_pow((double)(j + 1) - p->p_j, 2))
			+ ft_pow((double)(i - p->p_i), 2)); //LEFT
	if (a < b && a <= c && a <= d && (*node)->direction != DOWN)
		(*node)->direction = UP;
	else if (b <= c && b <= d && (*node)->direction != UP)
		(*node)->direction = DOWN;
	else if (c < d && (*node)->direction != LEFT)
		(*node)->direction = LEFT;
	else if ((*node)->direction != RIGHT)
		(*node)->direction = RIGHT;
}

void	enemy_patrol(t_win *win)
{
	t_enemy		*lst;
	int			i;
	int			j;

	lst = win->enemy;
	while (lst)
	{
		i = lst->i;
		j = lst->j;
		enemy_movement(win, &lst, win->player->p_i, win->player->p_i);
		if (lst->direction == UP)
			move_enemy(&lst, i - 1, j, win->map);
		else if (lst->direction == DOWN)
			move_enemy(&lst, i + 1, j, win->map);
		else if (lst->direction == LEFT)
			move_enemy(&lst, i, j - 1, win->map);
		else if (lst->direction == RIGHT)
			move_enemy(&lst, i, j + 1, win->map);
		hit_enemy(win, win->player->p_i, win->player->p_j);
		lst = lst->next;
	}
}
