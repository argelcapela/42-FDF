/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_center.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void align_center(t_dot *dot, t_fdf *fdf)
{
    float     x_center;
    float     y_center;

    if (fdf->view->isometric == 1)
        x_center = (fdf->window_width / 2)  - ((fdf->view->scale * (fdf->map_width / 3)) / 2);
    else 
        x_center = (fdf->window_width / 2)  - ((fdf->view->scale * fdf->map_width) / 2);

    y_center = (fdf->window_height / 2) - ((fdf->view->scale * fdf->map_height) / 2);
    dot->Xi += x_center;
    dot->Xf += x_center;
    dot->Yi += y_center;
    dot->Yf += y_center;
}