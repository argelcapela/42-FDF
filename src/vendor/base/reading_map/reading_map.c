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

void	reading_map(int argc, char **argv, t_fdf **fdf)
{
	int	fd;
	int tmp;

	error(argc, argv);
	(*fdf)->width = getting_width(argv[1]);
	(*fdf)->height = getting_height(argv[1]);
	tmp = (*fdf)->width;
	fd = open(argv[1], O_RDONLY);
	(*fdf)->matrix = fill_matrix((*fdf)->width, (*fdf)->height, fd, -1);
	print_matrix((*fdf)->matrix, (*fdf)->width, (*fdf)->height);
	close(fd);
	(*fdf)->width = tmp;
}
