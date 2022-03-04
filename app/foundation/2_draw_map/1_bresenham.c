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

void lineLow(int *X0, int *Y0, int *Xf, int *Yf, t_fdf *fdf)
{
    int dX = *Xf - *X0;
    int dY = *Yf - *Y0;

    int Yi = 1;
    if (dY < 0)
    {
        Yi = -1;
        dY = -(dY);
    }
    int D = (2 * dY) - dX;
    int y = *Y0;
    int x = *X0;

    while (x < *Xf)
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
        if (D > 0)
        {
            y = y + Yi;
            D = D + (2 * (dY - dX));
        }
        else
            D = D + (2 * dY);

        x++;
    }



}

void    bresenham(int X0, int Y0, int Xf, int Yf, t_fdf *fdf)
{
    link_draws_to_bresenham(&X0, &Y0, &Xf, &Yf, fdf);

    lineLow(&X0, &Y0, &Xf, &Yf, fdf);
   
    

}
      //else if (dX == 0 && dY > 0) // 2 caso - linha vertical Y (dX == 0 && dY > 0)
     //       Yi++;    

            // sleep(1);
            // ft_printf("\n%d %d\n", Xf - Xi , Yf - Yi);
       


// #define MAX(a, b) (a > b ? a : b)

// #define MOD(a) ((a < 0) ? -a : a)

// float mod(float i)
// {
//     return (i < 0) ? -i : i;
// }

// void    bresenham(float x, float y, float x1, float y1, t_fdf *fdf)
// {
//     int   x_step;
//     int   y_step;
//     float     max;

//     float     z;
//     float     z1;
//     // int     x_center;
//     // int     y_center;
    
//      z  = fdf->matrix[(int)x][(int)y];
//      z1 = fdf->matrix[(int)x1][(int)y1];

//     // /*---- color -----*/
//     // fdf->color = (z || z1) ? 0xe80c0c : 0xffffff;


//     // x *= fdf->zoom;
//     // y *= fdf->zoom;
//     // x1 *= fdf->zoom;
//     // y1 *= fdf->zoom;

//     // /*---adding 3D----*/
//     // if (fdf->perspective_3d)
//     // {
//          //add_isometric_projection(& x,  &y, z, fdf);
//         x = (x - y) * (cos(fdf->angle));
//         y = (x + y) * (sin(fdf->angle)) - z;

//         x1 = (x1 - y1) * (cos(fdf->angle));
//         y1 = (x1 + y1) * (sin(fdf->angle)) - z1;
//          //add_isometric_projection(&x1, &y1, z1, fdf);

//     // }
//     // /*----align center----*/
//     // x_center = (fdf->window_width / 2) - (fdf->width * 2) - 50;
//     // y_center = (fdf->window_height / 3) - (fdf->height);
//     // x += x_center;
//     // y += y_center;
//     // x1 += x_center;
//     // y1 += y_center;

//     // /*--shift----*/
//     // x += fdf->move_x;
//     // y += fdf->move_y;
//     // x1 += fdf->move_x;
//     // y1 += fdf->move_y;

        
 
//      x_step = x1 - x; // 2
//      y_step = y1 - y; // 11

//     max = MAX(MOD(x_step), MOD(y_step));
//     x_step /= max;
//     y_step /= max;
//     while ((int)(x - x1) || (int)(y - y1))
//     {

//         mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
//         x += x_step;
//         y += y_step;
//     }
// }