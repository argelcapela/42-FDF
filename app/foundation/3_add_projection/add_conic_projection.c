/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_conic_projection.c                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void    add_conic_projection(float *x, float *y, int z, t_fdf *fdf)	
{
    if (fdf)

    *x = (*x - *y) * (cos(fdf->angle));
    *y = (*x + *y) * (sin(fdf->angle)) - z;
}