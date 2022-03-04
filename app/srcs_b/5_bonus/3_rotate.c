/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_draws.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void rotate_xyz_with_mouse (t_dot *dot, t_fdf *fdf)
{
    if (dot && fdf)
    {
        
    }
}

void rotate_x(t_dot *dot, t_fdf *fdf)
{
    float *Yi = &dot->Yi;
    float *Zi = &dot->Zi;
    float *Yf = &dot->Yf;
    float *Zf = &dot->Zf;
    float *ax = &fdf->view->angle_x;

    *Yi = cos(*ax) * (*Yi) - sin(*ax) * (*Zi);
    *Zi = sin(*ax) * (*Yi) + cos(*ax) * (*Zi);
    *Yf = cos(*ax) * (*Yf) - sin(*ax) * (*Zf);
    *Zf = sin(*ax) * (*Yf) + cos(*ax) * (*Zf);
}

void rotate_y(t_dot *dot, t_fdf *fdf)
{
    float *Xi = &dot->Xi;
    float *Zi = &dot->Zi;
    float *Xf = &dot->Xf;
    float *Zf = &dot->Zf;
    float *ax = &fdf->view->angle_y;

    *Xi = cos(*ax)   * (*Xi) + sin(*ax) * (*Zi);
    *Zi = sin(*ax) * -(*Xi) + cos(*ax) * (*Zi);
    *Xf = cos(*ax)   * (*Xf) + sin(*ax) * (*Zf);
    *Zf = sin(*ax) * -(*Xf) + cos(*ax) * (*Zf);
}

void rotate_z(t_dot *dot, t_fdf *fdf)
{
    float *Xi = &dot->Xi;
    float *Yi = &dot->Yi;
    float *Xf = &dot->Xf;
    float *Yf = &dot->Yf;
    float *ax = &fdf->view->angle_z;

    *Xi = cos(*ax) * (*Xi) - sin(*ax) * (*Yi);
    *Yi = sin(*ax) * (*Xi) + cos(*ax) * (*Yi);
    *Xf = cos(*ax) * (*Xf) - sin(*ax) * (*Yf);
    *Yf = sin(*ax) * (*Xf) + cos(*ax) * (*Yf);
}
