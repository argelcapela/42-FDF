/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:45:54 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 18:56:51 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../fdf.h"

/*--------------------------------------------------
   "Using the map.fdf directory, we get the height
    and width of the map.fdf,read the map.fdf
    and fill matrix with them."
---------------------------------------------------*/

int	**reading_map(int argc, char **argv)
{
	int	**matrix;
	int	height;
	int	width;
	int	fd;

	error(argc, argv);
	height = 0;
	width = 0;
	height = getting_height(argv[1]);
	width = getting_width(argv[1]);
	matrix = NULL;
	fd = open(argv[1], O_RDONLY);
	matrix = fill_matrix(width, height, fd, -1);
	print_matrix(matrix, width, height);
	close(fd);
	while ((width - 1) >= 0)
		ft_free_ptr((void *) &matrix[--width]);
	ft_free_ptr((void *) &matrix);
	return (matrix);
}
