/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void    initialize_t_fdf_struct(t_fdf **fdf)
{	
    (*fdf)->window_width = 800;
    (*fdf)->window_height = 600;    
    (*fdf)->width = 0;
    (*fdf)->height = 0;
    (*fdf)->zoom = 20;
    (*fdf)->move_x = 20;
    (*fdf)->move_y = 20;
    (*fdf)->rotate_2d = 0;
    (*fdf)->rotate_3d = 0;
    (*fdf)->angle = 1;
    (*fdf)->perspective_3d = 0;
}