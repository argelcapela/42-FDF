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


void    put_image_pixel(t_fdf **fdf, int x, int y, int color)
{
    char    *pixel;

    if (x < 0 || x >= (*fdf)->window_width || y < 0 || y >= (*fdf)->window_height)
   return;
    pixel = (*fdf)->img->buffer + x * (32 / 8) + y * (*fdf)->img->line_bytes;

    pixel[0] = (color) &  0xFF;
    pixel[1] = (color >> 8) & 0xFF;
    pixel[2] = (color >> 16) & 0xFF;
    pixel[3] = (color >> 24);
}  


// void    put_image_pixel(t_dot **dot, t_fdf **fdf)
// {
//     int     pixel;
//     int     color;

//     if ((*dot)->Xi < 0 || (*dot)->Xi >= (*fdf)->window_width || (*dot)->Yi < 0 || (*dot)->Yi >= (*fdf)->window_height)
//     return;

//     pixel = ((*dot)->Yi * (*fdf)->img->line_bytes) + ((*dot)->Xi * 4);
    
//     color = mlx_get_color_value((*fdf)->mlx_ptr, (*fdf)->view->color);

//     (*fdf)->img->buffer[pixel + 0] = (color) &  0xFF;
//     (*fdf)->img->buffer[pixel + 1] = (color >> 8) & 0xFF;
//     (*fdf)->img->buffer[pixel + 2] = (color >> 16) & 0xFF;
//     (*fdf)->img->buffer[pixel + 3] = (color >> 24);
// }  

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
        //mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, dot->Xi, dot->Yi, fdf->view->color);
        //put_image_pixel(&dot, &fdf);
        put_image_pixel(&fdf, dot->Xi, dot->Yi, fdf->view->color);
        dot->Xi += x_step;
        dot->Yi += y_step;
    }
}

 

