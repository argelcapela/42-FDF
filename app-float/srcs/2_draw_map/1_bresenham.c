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

#include "../../headers/fdf.h"

/*--------------------------------------------------
   
   "Draw a line from point (Xi,Yi) 
   until (Xf, Yf)."

---------------------------------------------------*/

void    bresenham(t_dot *dot, t_fdf *fdf)
{
    link_draws_to_bresenham(&dot, fdf);
    float    x_step;
    float    y_step;
    float    larger;

    x_step = dot->Xf - dot->Xi; 
    y_step = dot->Yf - dot->Yi;    
    larger = LARGER(POSITIVE(x_step), POSITIVE(y_step));
    x_step /= larger;
    y_step /= larger;
    while ((int)(dot->Xi - dot->Xf) || (int)(dot->Yi - dot->Yf))
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, dot->Xi, dot->Yi, fdf->view->color);
        dot->Xi += x_step;
        dot->Yi += y_step;
    }
}

// void    put_image_pixel(t_img *img, t_dot *dot, t_fdf *fdf)
// {
//     char    *p;
//     int     i;

//     if (x < 0 || x >= fdf->window_width || y < 0 || y >= fdf->window_height)
//         return;
//     p = img->addr + dot->Xi * (img->bpp / 8) + dot->Yi * img->line_size;
//     (int *)(p) = dot->color;
// }   

