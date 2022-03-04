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

void draw_projection(int **Xi, int **Yi, int **Xf, int **Yf,int *z, int *z1, t_fdf *fdf)
{
    if (fdf->perspective_3d)
    {
        add_isometric_projection(*Xi, *Yi, *z, fdf);
        add_isometric_projection(*Xf, *Yf, *z1, fdf);
    }
}
        