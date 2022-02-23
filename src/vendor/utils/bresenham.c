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

    x_step = x1 - x; // 2
    x_step = y1 = y; // 11

    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while (1)
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
        x += x_step;
        y += y_step;
    }
}