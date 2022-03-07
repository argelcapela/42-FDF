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

#include "../../headers/fdf_bonus.h"

void    enable_bonus(t_dot **dot, t_fdf **fdf)
{
    decide_pixel_color(*dot, *fdf);
    zoom(dot, fdf);
    translate(*dot, *fdf);
    if ((*fdf)->view->free_rotation == 1)
    {
        rotate_z(*dot, *fdf);
        rotate_x(*dot, *fdf);
        rotate_y(*dot, *fdf);
    }
    align_center(*dot, *fdf);

}
