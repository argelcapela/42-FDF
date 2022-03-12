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

int	get_map_color(int x, int y, char *cel, t_fdf *fdf)
{
	int		n;
	char	*h;
	int		*h_int;
	char	*tmp_cel;
	int		len;

	tmp_cel = cel;
	h_int = NULL;
	while (*cel++)
		*cel = ft_toupper(*cel);
	cel = tmp_cel;
	if (ft_strchr(cel, 'X'))
	{
		h = ft_substr(cel, ft_indexof(cel, ',') + 4, ft_strlen(cel));
		if (ft_strchr(h, '\n'))
		{
			h = ft_str_replace(h, ft_chr_to_str('\n', 1), ft_strdup("X"));
			h = ft_substr(h, 0, ft_indexof(cel, 'X'));
		}
		n = ft_atoi(ft_substr(cel, 0, ft_indexof(cel, ',')));
		len = ft_strlen(h);
		if (len != 6)
		{
		 	tmp_cel = ft_str_merge(h, ft_chr_to_str('0', 6 - len));
		 	h = tmp_cel;
		}
		if (ft_strlen(h) == 6)
			h_int = ft_hexatoi(h);
		else
			h_int = 0;
		fdf->view->color_matrix[x][y] = *h_int;
	}
	else
		n = ft_atoi(cel);
	return (n);
}

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
			matrix[x][y] = get_map_color(x, y, split[x], fdf);
			//ft_atoi(split[x]);
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
