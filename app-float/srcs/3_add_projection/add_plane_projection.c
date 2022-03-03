/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane_projection.c                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void    add_plane_projection(float *x, float *y, float *z, t_fdf *fdf)
{
    if (fdf)
    {
        *x -= (*x -  *y) * cos(0);
        *y -= (*x +  *y) * sin(0) -  *z;
    }
}