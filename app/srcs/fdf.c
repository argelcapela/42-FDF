/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:19 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	parse_map(argc, argv);
	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	init_structs(&fdf);
	fdf->c_map_path = ft_printf_to_var("%s", argv[1]);
	fdf->c_map_name = ft_substr(fdf->c_map_path, 5, ft_strlen(fdf->c_map_path));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->window_width,
			fdf->window_height, "42-FDF By Argel Capela | 42 acapela-");
	init_img(fdf);
	render(&fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 0, on_release_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, on_destroy, fdf);
	mlx_expose_hook(fdf->win_ptr, expose, fdf);
	mlx_loop(fdf->mlx_ptr);
	free_mlx(fdf);
	free_fdf(fdf);
	return (0);
}
