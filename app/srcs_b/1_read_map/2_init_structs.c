/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/11 13:07:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	init_structs(t_fdf **fdf)
{
(*fdf)->window_width = 1270;
(*fdf)->window_height = 900;
(*fdf)->map_width = 0;
(*fdf)->map_height = 0;
(*fdf)->hint_box = 1;
(*fdf)->c_map = 0;
(*fdf)->view = (t_view *)malloc(sizeof(t_view));
(*fdf)->view->angle_x = 0;
(*fdf)->view->angle_y = 0;
(*fdf)->view->angle_z = 0;
(*fdf)->view->scale = 20;
(*fdf)->view->move_x = 20;
(*fdf)->view->move_y = 20;
(*fdf)->view->changing_color = 0;
(*fdf)->view->isometric = 0;
(*fdf)->view->color_matrix = NULL;
(*fdf)->f_alloc = 0;
(*fdf)->view->conic = 0;
(*fdf)->view->free_rotation = 0;
(*fdf)->img = (t_img *)malloc(sizeof(t_img));
(*fdf)->f_alloc = 0;
(*fdf)->view->color_matrix = NULL;
}
