/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:58:46 by suchua            #+#    #+#             */
/*   Updated: 2022/12/25 13:58:46 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_left_pic(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_destroy_image(win->mlx, win->player->p_img);
	win->player->p_img = mlx_xpm_file_to_image(win->mlx, "xpm/pl.xpm", &x, &y);
}

void	get_player_right_pic(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_destroy_image(win->mlx, win->player->p_img);
	win->player->p_img = mlx_xpm_file_to_image(win->mlx, "xpm/pr.xpm", &x, &y);
}
