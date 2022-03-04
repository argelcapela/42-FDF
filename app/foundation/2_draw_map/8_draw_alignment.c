/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_draws.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void draw_alignment(int **Xi, int **Yi, int **Xf, int **Yf, t_fdf *fdf)
{
    int     x_center;
    int     y_center;

    x_center = (fdf->window_width / 2) - (fdf->width * 2) - 50;
    y_center = (fdf->window_height / 3) - (fdf->height);
    *(*Xi) += x_center;
    *(*Yi) += y_center;
    *(*Xf) += x_center;
    *(*Yf) += y_center;
}