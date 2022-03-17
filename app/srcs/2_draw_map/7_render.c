/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:53:32 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	render(t_fdf **fdf)
{
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
	mlx_put_image_to_window((*fdf)->mlx_ptr, (*fdf)->win_ptr,
		(*fdf)->ptr_img, 0, 0);
}

int	rerender(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->ptr_img);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	init_img(fdf);
	render(&fdf);
	return (0);
}

int	expose(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->ptr_img, 0, 0);
	return (0);
}
