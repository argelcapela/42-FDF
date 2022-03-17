/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:53:14 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

/*--------------------------------------------------
	mlx_get_data_addr:
		-> pixel_bits: amount of bits per pixel.

		-> size_line: is the  number  of  bytes 
		used to store one line of the image in memory.

		-> endian: order in which a sequence of bytes is 
		stored in computer memory.
---------------------------------------------------*/

void	init_img(t_fdf *fdf)
{
	fdf->ptr_img = mlx_new_image(fdf->mlx_ptr, fdf->window_width,
			fdf->window_height);
	fdf->img->buffer = mlx_get_data_addr(fdf->ptr_img,
			&fdf->img->pixel_bits, &fdf->img->size_line,
			&fdf->img->endian);
}

void	init_structs(t_fdf **fdf)
{
(*fdf)->window_width = 800;
(*fdf)->window_height = 600;
(*fdf)->map_width = 0;
(*fdf)->map_height = 0;
(*fdf)->hint_box = 1;
(*fdf)->img = (t_img *)malloc(sizeof(t_img));
(*fdf)->f_alloc = 0;
(*fdf)->hb_msgs = NULL;
(*fdf)->all_maps_path = NULL;
(*fdf)->c_map_name = NULL;
(*fdf)->c_map_path = NULL;
(*fdf)->view = (t_view *)malloc(sizeof(t_view));
(*fdf)->view->angle_x = 0;
(*fdf)->view->angle_y = 0;
(*fdf)->view->angle_z = 0;
(*fdf)->view->scale = 7;
(*fdf)->view->move_x = 20;
(*fdf)->view->move_y = 20;
(*fdf)->view->changing_color = 0;
(*fdf)->view->isometric = 1;
(*fdf)->view->color_matrix = NULL;
(*fdf)->matrix = NULL;
}
