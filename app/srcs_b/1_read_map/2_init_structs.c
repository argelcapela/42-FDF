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

#include "../../headers/fdf_bonus.h"

void    init_structs(t_fdf **fdf)
{	
    (*fdf)->window_width = 800;
    (*fdf)->window_height = 600;    
    (*fdf)->map_width = 0;
    (*fdf)->map_height = 0;
    (*fdf)->hint_box = 1;
    (*fdf)->view = (t_view *)malloc(sizeof(t_view));
    (*fdf)->view->u_map_width = 0;
    (*fdf)->view->u_map_height = 0;
    (*fdf)->view->angle_x = 0; 
    (*fdf)->view->angle_y = 0; 
    (*fdf)->view->angle_z = 0; 
    (*fdf)->view->scale = 20;
    (*fdf)->view->move_x = 20;
    (*fdf)->view->move_y = 20;
    (*fdf)->view->changing_color = 0;
    (*fdf)->view->isometric = 0;
    (*fdf)->view->conic = 0;
    (*fdf)->view->free_rotation = 0;
    (*fdf)->img = (t_img *)malloc(sizeof(t_img));
}