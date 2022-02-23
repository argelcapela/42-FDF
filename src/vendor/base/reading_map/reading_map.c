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

int	**reading_map(char *path, int *x, int *y)
{
	int	**matrix;
	int	height;
	int	width;
	int	fd;

	height = 0;
	width = 0;
	height = getting_height(path);
	width = getting_width(path);
	*x = width;
	*y = height;
	matrix = NULL;
	fd = open(path, O_RDONLY);
	matrix = fill_matrix(width, height, fd, -1);
	print_matrix(matrix, width, height);
	close(fd);
	return (matrix);
}
