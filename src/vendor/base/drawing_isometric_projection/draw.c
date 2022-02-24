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

#include "../../../fdf.h"

/*--------------------------------------------------
   
   "It uses logic and bresenham to draw a line
    between all dots."

---------------------------------------------------*/

void draw(t_fdf *fdf)
{
   int   x;
   int   y;

   y = 0;
   while (y < fdf->height)
   {
      x = 0;
      while (x < fdf->width)
      {
         if (x < fdf->width - 1)
            bresenham(x, y, x + 1, y, fdf);
         if (y < fdf->height - 1)
            bresenham(x, y, x, y + 1, fdf);
         x++;
      }
      y++;
   }
}