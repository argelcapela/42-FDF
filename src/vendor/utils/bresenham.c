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
   
   "Draw a line between point (x,y) until (x1, y1)
    in screen.It is a utility super important for 
             the rest of the project."

  
    Where is this from?

    What is the logic in details?


---------------------------------------------------*/

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
    
    /*---- color -----*/
    //ft_printf("%d", fdf->matrix[1][1]);
    //ft_printf("%d", z);
    // z1 = fdf->z_matrix[(int)y1][(int)x1];

    z  = fdf->matrix[(int)x][(int)y];
    fdf->color = (z) ? 0xe80c0c : 0xffffff;
    if (z1 && z)
    {

    }
    /*----------------*/


    /*-------zoom----------*/
    x *= fdf->zoom;
    y *= fdf->zoom;
    x1 *= fdf->zoom;
    y1 *= fdf->zoom;
    /*---------------------*/

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