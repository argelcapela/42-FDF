/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*--------------------------------------------------
   
   "Draw a line from point (Xi,Yi) 
   until (Xf, Yf)."

---------------------------------------------------*/

// void static draw_zoom(int Xi, int Yi, int Xf, int Yf, t_fdf *fdf)
// {
//     x *= fdf->zoom;
//     y *= fdf->zoom;
//     x1 *= fdf->zoom;
//     y1 *= fdf->zoom;
// }

// void static draw_alignment(int Xi, int Yi, int Xf, int Yf, t_fdf *fdf)
// {
//     int     x_center;
//     int     y_center;

//     x_center = (fdf->window_width / 2) - (fdf->width * 2) - 50;
//     y_center = (fdf->window_height / 3) - (fdf->height);
//     x += x_center;
//     y += y_center;
//     x1 += x_center;
//     y1 += y_center;
// }

// void static draw_projection(int Xi, int Yi, int Xf, int Yf, t_fdf *fdf)
// {
//     if (fdf->perspective_3d)
//     {
//         add_isometric_projection(&x, &y, z, fdf);
//         add_isometric_projection(&x1, &y1, z1, fdf);
//     }
// }

// void static draw_projection(int Xi, int Yi, int Xf, int Yf, t_fdf *fdf)
// {
//     x += fdf->move_x;
//     y += fdf->move_y;
//     x1 += fdf->move_x;
//     y1 += fdf->move_y;
// }

// void static draw_color(int Xi, int Yi, int Xf, int Yf, t_fdf *fdf
// {
//     fdf->color = (z || z1) ? 0xe80c0c : 0xffffff;
// }

//     // int     z;
//     // int     z1;

//     // z  = fdf->matrix[(int)x][(int)y];
//     // z1 = fdf->matrix[(int)x1][(int)y1];

#define MAX(a, b) (a > b ? a : b)

#define MOD(a) ((a < 0) ? -a : a)

float mod(float i)
{
    return (i < 0) ? -i : i;
}

void    bresenham(float x, float y, float x1, float y1, t_fdf *fdf)
{
    float   x_step;
    float   y_step;
    int     max;

    int     z;
    int     z1;
    int     x_center;
    int     y_center;
    
    z  = fdf->matrix[(int)x][(int)y];
    z1 = fdf->matrix[(int)x1][(int)y1];

    /*---- color -----*/
    fdf->color = (z || z1) ? 0xe80c0c : 0xffffff;


    x *= fdf->zoom;
    y *= fdf->zoom;
    x1 *= fdf->zoom;
    y1 *= fdf->zoom;

    /*---adding 3D----*/
    if (fdf->perspective_3d)
    {
        add_isometric_projection(&x, &y, z, fdf);
        add_isometric_projection(&x1, &y1, z1, fdf);
    }
    /*----align center----*/
    x_center = (fdf->window_width / 2) - (fdf->width * 2) - 50;
    y_center = (fdf->window_height / 3) - (fdf->height);
    x += x_center;
    y += y_center;
    x1 += x_center;
    y1 += y_center;

    /*--shift----*/
    x += fdf->move_x;
    y += fdf->move_y;
    x1 += fdf->move_x;
    y1 += fdf->move_y;
 
     x_step = x1 - x; // 2
     y_step = y1 - y; // 11

    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
        x += x_step;
        y += y_step;
    }
}