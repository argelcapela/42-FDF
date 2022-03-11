/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	draw_line(t_dot *dot, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	larger;

	dot->Zi = (float)fdf->matrix[(int)dot->Xi][(int)dot->Yi];
	dot->Zf = (float)fdf->matrix[(int)dot->Xf][(int)dot->Yf];
	decide_pixel_color(dot, fdf);
	zoom(&dot, &fdf);
	isometric(&dot->Xi, &dot->Yi, &dot->Zi);
	isometric(&dot->Xf, &dot->Yf, &dot->Zf);
	align_center(dot, fdf);
	x_step = dot->Xf - dot->Xi;
	y_step = dot->Yf - dot->Yi;
	larger = LARGER(POSITIVE(x_step), POSITIVE(y_step));
	x_step /= larger;
	y_step /= larger;
	while ((int)(dot->Xi - dot->Xf) || (int)(dot->Yi - dot->Yf))
	{
		draw_pixel_in_image(&fdf, dot->Xi, dot->Yi, fdf->view->color);
		dot->Xi += x_step;
		dot->Yi += y_step;
	}
}
