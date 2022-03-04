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

static void update_dots_cordinates(float x, float y, t_dot **dot, int d)
{
   if (d == 1)
   {
      (*dot)->Xi = x;
      (*dot)->Yi = y;
      (*dot)->Xf = x + 1;
      (*dot)->Yf = y;
   }
   
   if (d == 2)
   {
     (*dot)->Xi = x;
     (*dot)->Yi = y;
     (*dot)->Xf = x;
     (*dot)->Yf = y + 1;
   }
}   

void draw_wireframe(t_fdf *fdf)
{
   int      x;
   int      y;
   t_dot    *dot; 

   y = -1;
   dot = (t_dot *) malloc(sizeof(t_dot));
   while (++y < fdf->map_height)
   {
      x = -1;
      while (++x < fdf->map_width)
      {
         if (x < fdf->map_width - 1)
         {
            update_dots_cordinates(x, y, &dot, 1);
            draw_line(dot, fdf);
         }
         if (y < fdf->map_height - 1)
         {
            update_dots_cordinates(x, y, &dot, 2);
            draw_line(dot, fdf);
         }
      }
   }
   ft_free_ptr((void *) &dot);
}