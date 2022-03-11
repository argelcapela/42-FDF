/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/07 21:15:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void	rotate_xyz_with_mouse(t_dot *dot, t_fdf *fdf)
{
	if (dot && fdf)
	{
	}
}

void	rotate_x(t_dot *dot, t_fdf *fdf)
{
	float	*ax;

	ax = &fdf->view->angle_x;
	dot->Yi = cos(*ax) * (dot->Yi) - sin(*ax) * (dot->Zi);
	dot->Zi = sin(*ax) * (dot->Yi) + cos(*ax) * (dot->Zi);
	dot->Yf = cos(*ax) * (dot->Yf) - sin(*ax) * (dot->Zf);
	dot->Zf = sin(*ax) * (dot->Yf) + cos(*ax) * (dot->Zf);
}

void	rotate_y(t_dot *dot, t_fdf *fdf)
{
	float	*ax;

	ax = &fdf->view->angle_y;
	dot->Xi = cos(*ax) * (dot->Xi) + sin(*ax) * (dot->Zi);
	dot->Xf = cos(*ax) * (dot->Xf) + sin(*ax) * (dot->Zf);
	dot->Zi = sin(*ax) * -(dot->Xi) + cos(*ax) * (dot->Zi);
	dot->Zf = sin(*ax) * -(dot->Xf) + cos(*ax) * (dot->Zf);
}

void	rotate_z(t_dot *dot, t_fdf *fdf)
{
	float		*ax;
	t_dot		*tmp_dot;

	tmp_dot = (t_dot *) malloc(sizeof(t_dot));
	ax = &fdf->view->angle_z;
	tmp_dot->Xi = dot->Xi;
	tmp_dot->Xf = dot->Xf;
	tmp_dot->Yi = dot->Yi;
	tmp_dot->Yf = dot->Yf;
	dot->Xi = cos(*ax) * (tmp_dot->Xi) - sin(*ax) * (tmp_dot->Yi);
	dot->Yi = sin(*ax) * (tmp_dot->Xi) + cos(*ax) * (tmp_dot->Yi);
	dot->Xf = cos(*ax) * (tmp_dot->Xf) - sin(*ax) * (tmp_dot->Yf);
	dot->Yf = sin(*ax) * (tmp_dot->Xf) + cos(*ax) * (tmp_dot->Yf);
}
