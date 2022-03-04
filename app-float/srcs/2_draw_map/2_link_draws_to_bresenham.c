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

#include "../../headers/fdf.h"

void    link_draws_to_bresenham(t_dot **dot, t_fdf *fdf)
{
    (*dot)->Zi = (float)fdf->matrix[(int)(*dot)->Xi][(int)(*dot)->Yi];
    (*dot)->Zf = (float)fdf->matrix[(int)(*dot)->Xf][(int)(*dot)->Yf];
    draw_zoom(*dot, fdf);
    draw_move(*dot, fdf);
    // ft_printf("antes %d %d %d %d\n", (int)(*dot)->Xi, (int)(*dot)->Yi, (int)(*dot)->Xf, (int)(*dot)->Yf );
    draw_projection(*dot, fdf);
    // ft_printf("depois %d %d %d %d\n", (int)(*dot)->Xi, (int)(*dot)->Yi, (int)(*dot)->Xf, (int)(*dot)->Yf );
    draw_color(*dot, fdf);
    draw_rotation_x(*dot, fdf);
    draw_rotation_y(*dot, fdf);
    draw_rotation_z(*dot, fdf);
    draw_alignment(*dot, fdf);
}
