/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:59 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

static void	dot_center(t_dot *tmp_dot, float ap[3])
{	
	tmp_dot->xi -= ap[0];
	tmp_dot->xf -= ap[0];
	tmp_dot->yi -= ap[1];
	tmp_dot->yf -= ap[1];
}

void	rotate_x(t_dot *dot, t_fdf *fdf)
{
	float		*ax;
	t_dot		tmp_dot;
	float		ap[3];

	ap[0] = (fdf->map_width) / 2;
	ap[1] = (fdf->map_height) / 2;
	ax = &fdf->view->angle_x;
	tmp_dot = *dot;
	dot_center(&tmp_dot, ap);
	dot->yi = cos(*ax) * (tmp_dot.yi) - sin(*ax) * (tmp_dot.zi);
	dot->zi = sin(*ax) * (tmp_dot.yi) + cos(*ax) * (tmp_dot.zi);
	dot->yf = cos(*ax) * (tmp_dot.yf) - sin(*ax) * (tmp_dot.zf);
	dot->zf = sin(*ax) * (tmp_dot.yf) + cos(*ax) * (tmp_dot.zf);
}

void	rotate_y(t_dot *dot, t_fdf *fdf)
{
	float		*ax;
	t_dot		tmp_dot;
	float		ap[3];

	ap[0] = (fdf->map_width) / 2;
	ap[1] = (fdf->map_height) / 2;
	ax = &fdf->view->angle_y;
	tmp_dot = *dot;
	dot_center(&tmp_dot, ap);
	dot->xi = cos(*ax) * (tmp_dot.xi) + sin(*ax) * (tmp_dot.zi);
	dot->xf = cos(*ax) * (tmp_dot.xf) + sin(*ax) * (tmp_dot.zf);
	dot->zi = sin(*ax) * -(tmp_dot.xi) + cos(*ax) * (tmp_dot.zi);
	dot->zf = sin(*ax) * -(tmp_dot.xf) + cos(*ax) * (tmp_dot.zf);
}

void	rotate_z(t_dot *dot, t_fdf *fdf)
{
	float		*ax;
	t_dot		tmp_dot;

	ax = &fdf->view->angle_z;
	tmp_dot = *dot;
	dot->xi = cos(*ax) * (tmp_dot.xi) - sin(*ax) * (tmp_dot.yi);
	dot->yi = sin(*ax) * (tmp_dot.xi) + cos(*ax) * (tmp_dot.yi);
	dot->xf = cos(*ax) * (tmp_dot.xf) - sin(*ax) * (tmp_dot.yf);
	dot->yf = sin(*ax) * (tmp_dot.xf) + cos(*ax) * (tmp_dot.yf);
}
