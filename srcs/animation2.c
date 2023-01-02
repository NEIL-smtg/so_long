/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:28:57 by suchua            #+#    #+#             */
/*   Updated: 2023/01/02 17:34:20 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	idle_animation(int is_moving, t_img *img, t_anim *a)
{
	if (is_moving)
		return ;
	if (img->p_img == a->pr1 || img->p_img == a->pr2)
		img->p_img = a->pr_idle1;
	else if (img->p_img == a->pl1 || img->p_img == a->pl2)
		img->p_img = a->pl_idle1;
	else if (img->p_img == a->pr_idle1)
		img->p_img = a->pr_idle2;
	else if (img->p_img == a->pr_idle2)
		img->p_img = a->pr_idle1;
	else if (img->p_img == a->pl_idle1)
		img->p_img = a->pl_idle2;
	else
		img->p_img = a->pl_idle1;
}
