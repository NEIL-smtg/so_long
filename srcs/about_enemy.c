/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:31:47 by suchua            #+#    #+#             */
/*   Updated: 2022/12/20 19:26:13 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_enemy(t_win *win)
{
	int			i;
	int			j;
	int			flag;
	int			cnt;
	t_ey_pos	*ey;

	cnt = 1;
	flag = 0;
	i = 0;
	j = 0;
	win->enemy->ey_pos = ft_calloc(1, sizeof(t_ey_pos));
	ey = win->enemy->ey_pos;
	while (cnt < win->map->w)
	{
		if (win->map->mapping[i][j] == '0')
		{
			flag = 1;
			ey->x = i;
			ey->y = j;
			ey->next = ft_calloc(1, sizeof(t_ey_pos));
			ey = ey->next;
		}
		++cnt;
	}
	if (flag)
		return ;
	free(win->enemy->ey_pos);
	free(win->enemy);
}

void	render_enemy(t_win *win)
{
	t_ey_pos	*tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	win->enemy->img = mlx_xpm_file_to_image(win->mlx, "xpm/pacman.xpm", &x, &y);
	tmp = win->enemy->ey_pos;
	while (tmp)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->enemy->img, tmp->y * 64, tmp->x * 64);
		tmp = tmp->next;
	}
}
