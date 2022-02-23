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

int	deal_key(int key, void *fdf)
{
	ft_printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf *fdf;

	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	fdf->matrix = reading_map(argc, argv);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "42-FDF");

	bresenham(10, 10, 600, 300, fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, NULL);
	mlx_loop(fdf->mlx_ptr);
	ft_free_ptr((void *) &fdf);
}
