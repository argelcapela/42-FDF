/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_align_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/07 21:09:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void align_center(t_dot *dot, t_fdf *fdf)
{
    float     x_center;
    float     y_center;
    
    //fdf->map_width = (fdf->view->scale * fdf->map_width)  * cos(fdf->view->angle_z);
    //exit(1);
    
    x_center = (fdf->window_width / 2)  - ((((fdf->view->scale * fdf->map_width) * cos(fdf->view->angle_z))  * cos(fdf->view->angle_x)) / 2);
    y_center = (fdf->window_height / 2) - ((((fdf->view->scale * fdf->map_height) * cos(fdf->view->angle_z)) * cos(fdf->view->angle_y)) / 2);

    printf("%lf\n", (fdf->view->scale * fdf->map_width) * cos(fdf->view->angle_z) - (fdf->view->scale * fdf->map_height) * cos(fdf->view->angle_z));

   
    dot->Xi += x_center;
    dot->Xf += x_center;
    dot->Yi += y_center;
    dot->Yf += y_center;


    // analise rotação z


}


// x_center = (fdf->window_width / 2)  - (( ((fdf->view->scale * fdf->map_width) * cos(fdf->view->angle_y)) * sin(fdf->view->angle_z) ) / 2);
//     y_center = (fdf->window_height / 2) - (( ((fdf->view->scale * fdf->map_height) * cos(fdf->view->angle_x)) * sin(fdf->view->angle_z) ) / 2);
  