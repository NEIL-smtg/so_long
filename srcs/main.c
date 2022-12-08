/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:40:48 by suchua            #+#    #+#             */
/*   Updated: 2022/12/09 00:40:48 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	doit(int key, t_init_ptr *ptr)
{
	if (key == 65307)
	{
		mlx_destroy_display(ptr->mlx_ptr);
		free(ptr);
		ptr = NULL;
		exit(EXIT_FAILURE);
	}
	ft_printf("hi\n");  
	mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, 100, 100, 0xFFFFFF);
	return (0);
}

int	main(void)
{
	t_init_ptr	*ptr;
	void		*img;
	int			x;
	int			y;

	x = 200;
	y = 200;
	ptr = malloc(sizeof(t_init_ptr));
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, 500, 500, "so long");
	mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(ptr->win_ptr, doit, ptr);
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 300, 300, 0xFFFFFF, "noshit");
	img = mlx_xpm_file_to_image(ptr->mlx_ptr, "xpm/1.xpm", &x, &y);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, img, 270, 370);
	mlx_loop(ptr->mlx_ptr);
}
