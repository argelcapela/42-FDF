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

#include "../../headers/fdf.h"

void    init_structs(t_fdf **fdf)
{	
    // fdf
    (*fdf)->window_width = 800;
    (*fdf)->window_height = 600;    
    (*fdf)->map_width = 0;
    (*fdf)->map_height = 0;
    // view
    (*fdf)->view = (t_view *)malloc(sizeof(t_view));
    (*fdf)->view->angle_x = 0; 
    (*fdf)->view->angle_y = 0; 
    (*fdf)->view->angle_z = 0; 
    (*fdf)->view->scale = 20;
    (*fdf)->view->move_x = 20;
    (*fdf)->view->move_y = 20;
}