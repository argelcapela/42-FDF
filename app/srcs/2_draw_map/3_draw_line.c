/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_draw_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:53:27 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

static float	ft_larger(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static float	ft_positive(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	draw_line(t_dot *dot, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	larger;

	dot->zi = (float)fdf->matrix[(int)dot->xi][(int)dot->yi];
	dot->zf = (float)fdf->matrix[(int)dot->xf][(int)dot->yf];
	decide_pixel_color(dot, fdf);
	isometric(&dot->xi, &dot->yi, &dot->zi);
	isometric(&dot->xf, &dot->yf, &dot->zf);
	zoom(&dot, &fdf);
	align_center(dot, fdf);
	x_step = dot->xf - dot->xi;
	y_step = dot->yf - dot->yi;
	larger = ft_larger(ft_positive(x_step), ft_positive(y_step));
	x_step /= larger;
	y_step /= larger;
	while ((int)(dot->xi - dot->xf) || (int)(dot->yi - dot->yf))
	{
		draw_pixel_in_image(&fdf, dot->xi, dot->yi, fdf->view->color);
		dot->xi += x_step;
		dot->yi += y_step;
	}
}
