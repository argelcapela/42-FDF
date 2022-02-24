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

int	deal_key(int key, t_fdf *fdf)
{
	if(fdf)
	ft_printf("%d\n", key);
	//-----------move
	if (key == 65364)
		fdf->move_y += 10;
	if (key == 65362)
		fdf->move_y -= 10;
	if (key == 65361)
		fdf->move_x -= 10;
	if (key == 65363)
		fdf->move_x += 10;
	//-----------zoom
	if (key == 65451)
		fdf->zoom += 5;
	if (key == 65453)
		fdf->zoom -= 5;
	//-----------rotation
	if (key == 44)
		fdf->angle -= 0.1;
	if (key == 46)
		fdf->angle += 0.1;
	
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf);
	return (0);
}



int	main(int argc, char *argv[])
{
	t_fdf *fdf;

	/*------reading map--------*/
	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	initialize_t_fdf(&fdf);
	reading_map(argc, argv, &fdf);

	/*------drawing map--------*/
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->window_width, fdf->window_height, "42-FDF");
	draw(fdf);

	/*----key hook-------------*/
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);

	/*------cleaning leaks--------*/
	ft_free_matrix((void ***) &(fdf->matrix), fdf->width);
	ft_free_ptr((void *) &fdf);
	return (0);
}
