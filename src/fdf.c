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

// int	deal_key(int key)
// {
// 	ft_printf("%d", key);
// 	return (0);
// }
//mlx_key_hook(fdf->win_ptr, deal_key, NULL);


int	main(int argc, char *argv[])
{
	t_fdf *fdf;

	/*------reading map--------*/
	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	reading_map(argc, argv, &fdf);
	//ft_printf("\n\n#%d#\n\n", fdf->width);

	/*------drawing map--------*/
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 800, 600, "42-FDF");
	fdf->zoom = 20;
	draw(fdf);
	mlx_loop(fdf->mlx_ptr);
	

	/*------cleaning leaks--------*/
	ft_free_matrix((void ***) &(fdf->matrix), fdf->width);
	ft_free_ptr((void *) &fdf);
	return (0);
}
