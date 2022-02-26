/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*--------------------------------------------------

	"-Receive the width and height of map.fdf,

	 -Create a matrix[width, height] and allocate
	  memory to it.

	 -Read the map.fdf and fill the matrix."

---------------------------------------------------*/

int	**fill_matrix(int width, int height, int fd, int x)
{
	char	**split;
	char	*line;
	int		**matrix;
	int		y;

	y = -1;
	matrix = malloc_matrix(width, height);
	while (++y < height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		while (++x < width)
		{
			matrix[x][y] = ft_atoi(split[x]);
			ft_free_ptr((void *) &split[x]);
		}
		x = -1;
		ft_free_ptr((void *) &line);
		ft_free_ptr((void *) &split);
	}
	line = get_next_line(fd);
	ft_free_ptr((void *) &line);
	return (matrix);
}
