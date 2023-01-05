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

//events
# define KEY_PRESS 2
# define KEY_RELEASE 3

//player movement
# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4
//map feature
# define WALL 1
# define COIN 2
# define EX 3

//for visited path
typedef struct s_vis
{
	int		**vis;
	int		c;
}	t_vis;

typedef struct s_player
{
	int		p_i;
	int		p_j;
	int		ori_pi;
	int		ori_pj;
	int		steps;
	int		score;
	int		lives;
	int		is_moving;
}	t_player;

typedef struct s_enemy
{
	int				i;
	int				j;
	int				direction;
	void			*img;
	int				**path;
	struct s_enemy	*next;
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
	int			n;
	t_vis		*v;
}	t_map;

typedef struct s_anim
{
	void	*pr1;
	void	*pr2;
	void	*pl1;
	void	*pl2;
	void	*pr_idle1;
	void	*pr_idle2;
	void	*pr_idle3;
	void	*pl_idle1;
	void	*pl_idle2;
	void	*pl_idle3;
	void	*ex_img;
	void	*ex_open_img;
	void	*demon_r1;
	void	*demon_r2;
	void	*demon_r3;
	void	*lives_full;
	void	*lives_half;
	void	*lives_low;
	void	*lives_dead;
}	t_anim;

typedef struct s_img
{
	void	*c_img;
	void	*empty_img;
	void	*w_img;
	void	*ex_img;
	void	*p_img;
	void	*health_bar;
	void	*steps_img;
	void	*sc_c_img;
	t_anim	*anim;
}	t_img;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			frame;
	int			pause;
	t_map		*map;
	t_player	*player;
	t_enemy		*enemy;
	t_img		*img;
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

//make sure there is always a path to win
void	is_there_a_path(t_win *win);
void	get_new_vis(t_win *win, int a);
void	dfs_c(int i, int j, t_map *map, int *a);
void	dfs_e(int i, int j, t_map *map, int *a2);
void	clear_vis(t_vis *v, int h, int w);
void	free_vis(t_vis *v, int h);

//init
void	init(t_win *win, int *x, int *y);
void	set_player_pos(t_win *win);

//enemy
void	add_enemy_to_list(t_win *win, int i, int j);
void	enemy_patrol(t_win *win);
int		get_enemy_size(t_enemy *lst);
void	hit_enemy(t_win *win, int i, int j);

//update
void	refresh_screen(t_win *win);

// print steps in terminal
void	print_step(char *step);

//render map
void	render_map(t_win *win);
void	render_enemy(t_win *win);
void	put_img(char c, t_win *win, int x, int y);

//animation
int		animation(t_win *win);
void	health_bar_animation(int lives, t_anim *a, t_img *i);
int		stop_animation(int keycode, t_win *win);
void	player_idle(int is_moving, t_img *img, t_anim *a);
void	spawn_player_animation(t_win *win);
void	player_animation_transition(t_img *img, t_anim *a, int dir);

//math
double	ft_pow(double x, int n);
double	ft_sqrt(double nb);

//movement
int		key_on_pressed(int keycode, t_win *win);

//handle score and exit
void	handle_score(t_win *win, int i, int j);
int		game_over(t_win *win);

//destroy all malloced thingy, destroy images and display
void	destroy_everything(t_win *win);

#endif
