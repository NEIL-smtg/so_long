/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:10:44 by suchua            #+#    #+#             */
/*   Updated: 2023/01/05 16:14:13 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

double	ft_pow(double x, int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = ft_abs(n);
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
