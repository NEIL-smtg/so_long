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
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_init_ptr
{
	void	*win_ptr;
	void	*mlx_ptr;
}	t_init_ptr;

typedef struct s_map_status
{
	int	empty;
	int	wall;
	int	collectibles;
	int	exit;
	int	pos;
	int	len;
} map_status;


void	ft_parse_map(int ac, char **av);

#endif