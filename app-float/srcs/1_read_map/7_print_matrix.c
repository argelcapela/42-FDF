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

#include "../../headers/fdf.h"

void	print_matrix(int **matrix, int width, int height, char *map_path)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	ft_printf("\nYou loaded the map: %s\n\n", map_path);
	while (++y < height)
	{
		while (++x < width)
			ft_printf("%3d", matrix[x][y]);
		x = -1;
		ft_printf("\n");
	}
	ft_printf("\n");
	ft_printf("The window with you map drawed will be opened soon... Enjoy it! XD!");
}
