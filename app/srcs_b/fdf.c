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

#include "../headers/fdf_bonus.h"

int	main(int argc, char *argv[])
{
	t_fdf *fdf;

	parse_map(argc, argv);
	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	init_structs(&fdf);
	change_map(argv, fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->window_width, fdf->window_height, "42-FDF By Argel Capela | 42 acapela-");
	render(&fdf);
	mlx_key_hook(fdf->win_ptr, on_release_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, on_destroy, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, on_mouse_down, fdf);
	mlx_hook(fdf->win_ptr, 6, 0, on_mouse_move, fdf);
	mlx_expose_hook(fdf->win_ptr, rerender, fdf);
	mlx_loop(fdf->mlx_ptr);
	ft_free_matrix((void ***) &(fdf->matrix), fdf->map_width);
	ft_free_ptr((void *) &fdf);
	return (0);
}
