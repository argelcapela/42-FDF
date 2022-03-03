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

void draw_color(t_dot *dot, t_fdf *fdf)
{
    if (fdf->view->changing_color == 0)
        fdf->view->color = (dot->Zi || dot->Zf) ? AC_GREEN1 : 0xffffff;
    else if (fdf->view->changing_color == 1)
        fdf->view->color = (dot->Zi || dot->Zf) ? fdf->view->new_color1 : 0xffffff;
}
