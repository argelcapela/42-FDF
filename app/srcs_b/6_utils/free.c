/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:35 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	free_mlx(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->ptr_img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	ft_free_ptr((void *) &fdf->mlx_ptr);
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf->all_maps_path != NULL)
	{
		ft_free_matrix((void ***) &fdf->all_maps_path, fdf->amount_of_maps);
		ft_free_ptr((void *) &fdf->all_maps_path);
	}
	if (fdf->view->color_matrix != NULL)
	{
		ft_free_matrix((void ***) &fdf->view->color_matrix, fdf->map_width);
		ft_free_ptr((void *) &fdf->view->color_matrix);
	}
	ft_free_ptr((void *) &fdf->hb_msgs);
	ft_free_ptr((void *) &fdf->c_map_name);
	ft_free_ptr((void *) &fdf->c_map_path);
	ft_free_ptr((void *) &fdf->img);
	ft_free_matrix((void ***) &fdf->matrix, fdf->map_width);
	ft_free_ptr((void *) &fdf->matrix);
	ft_free_ptr((void *) &fdf->view);
	ft_free_ptr((void *) &fdf);
}

void	free_array_char(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (fdf->hb_msgs[i])
	{
		free (fdf->hb_msgs[i]);
		i++;
	}
	free(fdf->hb_msgs);
	fdf->hb_msgs = NULL;
}
