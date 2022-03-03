/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw    .c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

/*--------------------------------------------------
   
   "It uses logic and bresenham to draw a line
    between all dots."

---------------------------------------------------*/

void draw_map(t_fdf *fdf)
{
   int      x;
   int      y;
   t_dot    *dot; 

   y = 0;
   dot = (t_dot *) malloc(sizeof(t_dot));   
   while (y < fdf->map_height)
   {
      x = 0;
      while (x < fdf->map_width)
      {
         if (x < fdf->map_width - 1)
         {
            dot->Xi = x;
            dot->Yi = y;
            dot->Xf = x + 1;
            dot->Yf = y;
            bresenham(dot, fdf);
         }
         if (y < fdf->map_height - 1)
         {
            dot->Xi = x;
            dot->Yi = y;
            dot->Xf = x;
            dot->Yf = y + 1;
            bresenham(dot, fdf);
         }
         x++;
      }
      y++;
   }
   ft_free_ptr((void *) &dot);
   hint_box(&fdf);
}