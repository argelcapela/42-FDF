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

#include "../../fdf.h"

void    link_draws_to_bresenham(int *Xi, int *Yi, int *Xf, int *Yf, t_fdf *fdf)
{
    // int     z;
    // int     z1;

    // z  = fdf->matrix[*Xi][*Yi];
    // z1 = fdf->matrix[*Xf][*Yf];
   
    draw_zoom(&Xi, &Yi, &Xf, &Yf, fdf);
    draw_move(&Xi, &Yi, &Xf, &Yf, fdf);
    draw_rotation(&Xi, &Yi, &Xf, &Yf, fdf);
    //draw_projection(&Xi, &Yi, &Xf, &Yf, &z, &z1, fdf);
    //draw_color(&z, &z1, fdf);
    draw_alignment(&Xi, &Yi, &Xf, &Yf, fdf);
}
