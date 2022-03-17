/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_align_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:55:18 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void	align_center(t_dot *dot, t_fdf *fdf)
{
	float	width;
	float	height;
	float	hb;

	width = ((fdf->map_width)
			* cos(fdf->view->angle_y));
	height = ((fdf->map_height)
			* cos(fdf->view->angle_x));
	if (fdf->hint_box == 1)
		hb = 250;
	else
		hb = 0;
	fdf->view->x_origin = ((fdf->window_width + hb) / 2)
		- (width / 2);
	fdf->view->y_origin = ((fdf->window_height) / 2)
		- (height / 2);
	dot->xi += fdf->view->x_origin;
	dot->xf += fdf->view->x_origin;
	dot->yi += fdf->view->y_origin;
	dot->yf += fdf->view->y_origin;
}
