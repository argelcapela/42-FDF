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

void	render(t_fdf **fdf)
{
	t_rectangle *rect;
	t_image		*logo;
	t_image		*fdf_logo;

	(*fdf)->ptr_img = mlx_new_image((*fdf)->mlx_ptr, (*fdf)->window_width,
			(*fdf)->window_height);
	(*fdf)->img->buffer = mlx_get_data_addr((*fdf)->ptr_img,
			&(*fdf)->img->pixel_bits, &(*fdf)->img->line_bytes,
			&(*fdf)->img->endian);
	if ((*fdf)->view->color_matrix)
	{
	 	ft_free_matrix((void ***) &(*fdf)->view->color_matrix,
	 		(*fdf)->map_width);
	 	ft_free_ptr((void *) &(*fdf)->view->color_matrix);
	}
	if ((*fdf)->matrix)
	{
	 	ft_free_matrix((void ***) &(*fdf)->matrix, (*fdf)->map_width);
		ft_free_ptr((void *) &(*fdf)->matrix);
	}
	read_map(fdf);
	draw_wireframe(fdf);
	rect = (t_rectangle *) malloc(sizeof(t_rectangle));
	rect->x = 0;
	rect->y = 0;
	rect->width = 250;
	rect->height = 900;
	rect->color = AC_GREEN2;
	draw_rectangle(rect, (*fdf));
	mlx_put_image_to_window((*fdf)->mlx_ptr,
		(*fdf)->win_ptr, (*fdf)->ptr_img, 0, 0);
	//---logo
	logo = (t_image *) malloc(sizeof(t_image));
	logo->width = 10;
	logo->height = 10;
	logo->path = ft_strdup("assets/logo-small.xpm");
	logo->ptr = mlx_xpm_file_to_image((*fdf)->mlx_ptr, logo->path, &logo->width, &logo->height);
	mlx_put_image_to_window((*fdf)->mlx_ptr,
	 	(*fdf)->win_ptr, logo->ptr, 30, (*fdf)->window_height - 200);
	//---fdf_logo
	fdf_logo = (t_image *) malloc(sizeof(t_image));
	fdf_logo->width = 15;
	fdf_logo->height = 15;
	fdf_logo->path = ft_strdup("assets/fdf-bonus-logo.xpm");
	fdf_logo->ptr = mlx_xpm_file_to_image((*fdf)->mlx_ptr, fdf_logo->path, &fdf_logo->width, &fdf_logo->height);
	mlx_put_image_to_window((*fdf)->mlx_ptr,
	 	(*fdf)->win_ptr, fdf_logo->ptr, 50, 10);
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
