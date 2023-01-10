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

double	sum_pow(int i1, int i2, int j1, int j2)
{
	double	a;
	double	b;

	a = ft_pow((double)(i1 - i2), 2);
	b = ft_pow((double)(j1 - j2), 2);
	return (a + b);
}

void	enemy_movement(t_win *win, t_enemy **node, int i, int j)
{
	t_player	*p;
	double		a;
	double		b;
	double		c;
	double		d;

	p = win->player;
	a = ft_sqrt(sum_pow(i - 1, p->p_i, j, p->p_j));
	b = ft_sqrt(sum_pow(i + 1, p->p_i, j, p->p_j));
	c = ft_sqrt(sum_pow(i, p->p_i, j - 1, p->p_j));
	d = ft_sqrt(sum_pow(i, p->p_i, j + 1, p->p_j));
	if (a < b && a <= c && a <= d && (*node)->direction != UP)
		(*node)->direction = UP;
	else if (b <= c && b <= d && (*node)->direction != DOWN)
		(*node)->direction = DOWN;
	else if (c < d)
		(*node)->direction = LEFT;
	else
		(*node)->direction = RIGHT;
}

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
		enemy_movement(win, &lst, i, j);
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
