/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_enable_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:38 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void	enable_bonus(t_dot **dot, t_fdf **fdf)
{
	(*dot)->zi *= (*fdf)->view->depth_scale;
	(*dot)->zf *= (*fdf)->view->depth_scale;
	decide_pixel_color(*dot, *fdf);
	rotate_x(*dot, *fdf);
	rotate_y(*dot, *fdf);
	rotate_z(*dot, *fdf);
	if ((*fdf)->view->isometric == 1)
	{
		isometric(&(*dot)->xi, &(*dot)->yi, &(*dot)->zi);
		isometric(&(*dot)->xf, &(*dot)->yf, &(*dot)->zf);
	}
	zoom(dot, fdf);
	translate(*dot, *fdf);
	align_center(*dot, *fdf);
}
