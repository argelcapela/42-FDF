/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*--------------------------------------------------
  "..."

  	
---------------------------------------------------*/

int	main(int argc, char *argv[])
{
	t_fdf *fdf;

	/*------reading map--------*/
	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	initialize_t_fdf_struct(&fdf);
	read_map(argc, argv, &fdf);

	/*------drawing map--------*/
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->window_width, fdf->window_height, "42-FDF");
	draw_map(fdf);

	/*----key hook-------------*/
	mlx_key_hook(fdf->win_ptr, detect_input, fdf);
	mlx_loop(fdf->mlx_ptr);

	/*---persist when hide and return window*/


	/*------cleaning leaks--------*/
	ft_free_matrix((void ***) &(fdf->matrix), fdf->width);
	ft_free_ptr((void *) &fdf);
	return (0);
}
