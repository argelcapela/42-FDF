/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	print_matrix(int **matrix, int width, int height)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++y < height)
	{
		while (++x < width)
			ft_printf("%3d", matrix[x][y]);
		x = -1;
		ft_printf("\n");
	}
}
