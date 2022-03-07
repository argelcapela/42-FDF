/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void render(t_fdf **fdf)
{
    (*fdf)->ptr_img = mlx_new_image((*fdf)->mlx_ptr, (*fdf)->window_width, (*fdf)->window_height);
    (*fdf)->img->buffer = mlx_get_data_addr((*fdf)->ptr_img, &(*fdf)->img->pixel_bits, &(*fdf)->img->line_bytes, &(*fdf)->img->endian);
    read_map(fdf);
    draw_wireframe(fdf);
    mlx_put_image_to_window((*fdf)->mlx_ptr, (*fdf)->win_ptr, (*fdf)->ptr_img, 0, 0);
    if ((*fdf)->hint_box == 1)
    hint_box(fdf);
}

int	rerender(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->ptr_img);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	render(&fdf);
	return (0);
}