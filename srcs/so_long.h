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

#ifndef SO_LONG
# define SO_LONG

# include "../Libft/libft.h"
# include "../Libft/get_next_line/get_next_line_bonus.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map
{
	char	**mapping;
	int		h;
	int		w;
	int		empty;
	int		wall;
	int		c;
	int		e;
	int		p;
} t_map;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_map	*map;
} t_win;

//map
void	ft_check_map_path(char *path);
void	get_map(char *path, t_win *win);

//check valid map
void	check_len(t_map *map);
void	check_collectible_exit(t_map *map);
void	check_start_pos(t_map *map);
void	check_invalid_ch(t_map *map);

#endif