/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:03:26 by suchua            #+#    #+#             */
/*   Updated: 2023/01/10 19:13:47 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_step(char *step)
{
	char	*msg;

	msg = ft_strjoin("Your move : ", step);
	ft_putendl_fd(msg, 1);
	free(msg);
	free(step);
}
