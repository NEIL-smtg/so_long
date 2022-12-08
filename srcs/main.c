/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:49:46 by suchua            #+#    #+#             */
/*   Updated: 2022/12/07 00:49:46 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*winptr;
	void	*mlxptr;
} t_data;

int	doit(int key, t_data *data)
{
	ft_printf("hi");
	mlx_pixel_put(data->mlxptr, data->winptr, 100, 100, 0xFFFFFF);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	data;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so fucking long");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	data.mlxptr = mlx_ptr;
	data.winptr = win_ptr;
	mlx_key_hook(win_ptr, doit, &data);
	mlx_loop(mlx_ptr);
}