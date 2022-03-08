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
    *Xf = cos(*ax)   * (*Xf) + sin(*ax) * (*Zf);
    *Zi = sin(*ax)   * -(*Xi) + cos(*ax) * (*Zi);
    *Zf = sin(*ax)   * -(*Xf) + cos(*ax) * (*Zf);
}

void rotate_z(t_dot *dot, t_fdf *fdf)
{
    float *Xi = &dot->Xi;
    float *Yi = &dot->Yi;
    float *Xf = &dot->Xf;
    float *Yf = &dot->Yf;
    float *ax = &fdf->view->angle_z;

    float tmp_xi = *Xi;
    float tmp_xf = *Xf;
    float tmp_yi = *Yi;
    float tmp_yf = *Yf;

    *Xi = cos(*ax) * (tmp_xi) - sin(*ax) * (tmp_yi);
    *Yi = sin(*ax) * (tmp_xi) + cos(*ax) * (tmp_yi); 
    *Xf = cos(*ax) * (tmp_xf) - sin(*ax) * (tmp_yf);
    *Yf = sin(*ax) * (tmp_xf) + cos(*ax) * (tmp_yf);
}
