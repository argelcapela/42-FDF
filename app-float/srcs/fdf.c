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

#include "../headers/fdf.h"

int	rerender(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->ptr_img);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	render(&fdf);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf *fdf;

	parse_map(argc, argv);
	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	init_structs(&fdf);
	prepare_for_change_map(argv, &fdf);
	read_map(&fdf);

	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->window_width, fdf->window_height, "42-FDF");
	render(&fdf);
	mlx_key_hook(fdf->win_ptr, shoot_events_when_press_keys, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, shoot_events_when_use_mouse, fdf);
	mlx_expose_hook(fdf->win_ptr, rerender, fdf);
	mlx_loop(fdf->mlx_ptr);
	ft_free_matrix((void ***) &(fdf->matrix), fdf->map_width);
	ft_free_ptr((void *) &fdf);
	return (0);
}

