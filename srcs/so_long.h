/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:48:18 by suchua            #+#    #+#             */
/*   Updated: 2022/12/07 00:48:18 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../Libft/get_next_line/get_next_line_bonus.h"
# include <fcntl.h>
# include <mlx.h>

# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4


//for visited path
typedef struct s_vis
{
	int		**vis;
}	t_vis;

typedef struct s_player
{
	int		p_i;
	int		p_j;
	int		score;
	void	*p_img;
}	t_player;

typedef struct s_enemy_pos
{
	int		x;
	int		y;
	void	*next;
}	t_ey_pos;

typedef struct s_enemy
{
	int			x;
	int			y;
	void		*img;
	t_ey_pos	*ey_pos;
}	t_enemy;

typedef struct s_map
{
	char		**mapping;
	int			h;
	int			w;
	int			empty;
	int			wall;
	int			c;
	int			e;
	int			p;
	void		*c_img;
	void		*empty_img;
	void		*w_img;
	void		*ex_img;
	t_vis		*v;
}	t_map;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	t_map		*map;
	t_player	*player;
	t_enemy		*enemy;
}	t_win;

//map
void	ft_check_map_path(char *path);
void	get_map(char *path, t_win *win);

//check valid map
void	check_len(t_map *map);
void	check_collectible_exit(t_map *map);
void	check_start_pos(t_map *map);
void	check_invalid_ch(t_map *map);
void	free_map_exit(t_map *map);
void	good_map_structure(t_map *map);
void	is_there_a_path(t_win *win);

//render map
void	update_pos_and_render(t_win *win, int type);
void	render_map(t_win *win);
void	put_enemy(t_win *win);
void	render_enemy(t_win *win);

//movement
void	move_up(t_win *win);
void	move_down(t_win *win);
void	move_left(t_win *win);
void	move_right(t_win *win);
int		key_on_pressed(int keycode, t_win *win);
void	get_player_pos(t_win *win);

//handle score and exit
void	handle_score(t_win *win);
int		game_over(t_win *win);

//destroy all malloced thingy, destroy images and display
void	destroy_everything(t_win *win);

#endif
