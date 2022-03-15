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

void	init_img(t_fdf *fdf)
{
	fdf->ptr_img = mlx_new_image(fdf->mlx_ptr, fdf->window_width,
			fdf->window_height);
	fdf->img->buffer = mlx_get_data_addr(fdf->ptr_img,
			&fdf->img->pixel_bits, &fdf->img->line_bytes,
			&fdf->img->endian);
}

static void	init_view(t_fdf **fdf)
{
(*fdf)->view->mouse_translate = 0;
(*fdf)->view->mouse_rotate = 0;
(*fdf)->view->angle_x = 0;
(*fdf)->view->angle_y = 0;
(*fdf)->view->angle_z = 0;
(*fdf)->view->scale = 1;
(*fdf)->view->move_x = 20;
(*fdf)->view->move_y = 20;
(*fdf)->view->changing_color = 0;
(*fdf)->view->isometric = 0;
(*fdf)->view->color_matrix = NULL;
(*fdf)->view->conic = 0;
(*fdf)->view->free_rotation = 0;
(*fdf)->view->color_matrix = NULL;
(*fdf)->view->x_origin = 0;
(*fdf)->view->y_origin = 0;
}

void	init_structs(t_fdf **fdf)
{
(*fdf)->window_width = 1270;
(*fdf)->window_height = 900;
(*fdf)->map_width = 0;
(*fdf)->map_height = 0;
(*fdf)->hint_box = 1;
(*fdf)->hb_width = 250;
(*fdf)->c_map = 0;
(*fdf)->changing_map = 1;
(*fdf)->img = (t_img *)malloc(sizeof(t_img));
(*fdf)->f_alloc = 0;
(*fdf)->matrix = NULL;
(*fdf)->view = (t_view *)malloc(sizeof(t_view));
	init_view(fdf);
}
