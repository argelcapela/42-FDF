/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_fill_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/08 21:25:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

/*--------------------------------------------------

	"-Receive the width and height of map.fdf,

	 -Create a matrix[width, height] and allocate
	  memory to it.

	 -Read the map.fdf and fill the matrix."

---------------------------------------------------*/

// int	get_map_color(int x, int y, char *cel, t_fdf *fdf)
// {
// 	char	*hexa_color;
// 	int		*hexa_converted_int;
// 	char	*deepness;

// 	if (ft_strchr(cel, 'x') || ft_strchr(cel, 'X'))
// 	{
// 		if (ft_strchr(cel, 'x'))
// 		{
// 			hexa_color = ft_substr(cel, ft_indexof(cel, 'x'), ft_strlen(cel));
// 			deepness = ft_substr(cel, 0, ft_indexof(cel, 'x') - 1);
// 		}
// 		else if (ft_strchr(cel, 'X'))
// 		{
// 			hexa_color = ft_substr(cel, ft_indexof(cel, 'X'), ft_strlen(cel));
// 			deepness = ft_substr(cel, 0, ft_indexof(cel, 'X') - 1);
// 		}
// 		hexa_converted_int = ft_hexatoi(hexa_color);
// 		fdf->view->color_matrix[x][y] = *hexa_converted_int;
// 		ft_free_ptr((void *) &hexa_converted_int);
// 		return (ft_atoi(deepness));
// 	}
// 	return (ft_atoi(cel));
// }

int	**fill_matrix(int width, int height, t_fdf *fdf, int x)
{
	char	**split;
	char	*line;
	int		**matrix;
	int		y;

	y = -1;
	matrix = malloc_matrix(width, height);
	while (++y < height)
	{
		line = get_next_line(fdf->map_fd);
		split = ft_split(line, ' ');
		while (++x < width)
		{
			matrix[x][y] = ft_atoi(split[x]);
			//get_map_color(x, y, split[x], fdf);
			ft_free_ptr((void *) &split[x]);
		}
		x = -1;
		ft_free_ptr((void *) &line);
		ft_free_ptr((void *) &split);
	}
	line = get_next_line(fdf->map_fd);
	ft_free_ptr((void *) &line);
	return (matrix);
}
