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

void draw_projection(t_dot *dot, t_fdf *fdf)
{
    if (fdf->view->isometric == 1)
    {
        add_isometric_projection(&dot->Xi, &dot->Yi, &dot->Zi, fdf);
        add_isometric_projection(&dot->Xf, &dot->Yf, &dot->Zf, fdf);
    }
}
        