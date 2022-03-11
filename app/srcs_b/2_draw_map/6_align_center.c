/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_align_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/07 21:09:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void	align_center(t_dot *dot, t_fdf *fdf)
{
	float	x_center;
	float	y_center;
	float	width;
	float	height;

	width = ((fdf->view->scale * fdf->map_width) * cos(fdf->view->angle_y));
	height = ((fdf->view->scale * fdf->map_height) * cos(fdf->view->angle_x));
	x_center = ((fdf->window_width + 250) / 2) - (width / 2);
	y_center = ((fdf->window_height) / 2) - (height / 2);
	dot->Xi += x_center;
	dot->Xf += x_center;
	dot->Yi += y_center;
	dot->Yf += y_center;
}
