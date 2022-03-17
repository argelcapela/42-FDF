/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:31 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf_bonus.h"

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	parse_map(argc, argv);
	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	init_structs(&fdf);
	change_map(argv, fdf);
	set_initial_scale(fdf->c_map, &fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->window_width,
			fdf->window_height, "42-FDF By Argel Capela | 42 acapela-");
	init_img(fdf);
	fdf->view->isometric = 1;
	render(&fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 0, on_release_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, on_destroy, fdf);
	mlx_hook(fdf->win_ptr, 4, 1L << 2, on_mouse_down, fdf);
	mlx_expose_hook(fdf->win_ptr, expose, fdf);
	if (fdf->mlx_ptr)
		mlx_loop(fdf->mlx_ptr);
	free_mlx(fdf);
	free_fdf(fdf);
	return (0);
}
