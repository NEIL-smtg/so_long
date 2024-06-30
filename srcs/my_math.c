/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:10:44 by suchua            #+#    #+#             */
/*   Updated: 2024/06/30 19:33:46 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

double	ft_pow(double x, int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		x = 1 / x;
	}
	if (n % 2 == 0)
		return (ft_pow(x * x, n / 2));
	return (x * ft_pow(x, n - 1));
}

double	ft_sqrt(double nb)
{
	double	root;
	int		i;

	root = 1;
	i = 0;
	while (1)
	{
		++i;
		root = (nb / root + root) / 2;
		if (i == nb + 1)
			break ;
	}
	return (root);
}
