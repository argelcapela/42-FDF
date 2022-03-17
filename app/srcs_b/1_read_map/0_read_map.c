/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:45:54 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:13 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

/*--------------------------------------------------
   "Using the map.fdf directory, we get the height
    and width of the map.fdf,read the map.fdf
    and fill matrix with them."
---------------------------------------------------*/

void	read_map(t_fdf **fdf)
{
	int	fd;
	int	tmp;

	fd = open((*fdf)->c_map_path, O_RDONLY);
	(*fdf)->map_width = get_width((*fdf)->c_map_path);
	(*fdf)->map_height = get_height((*fdf)->c_map_path);
	(*fdf)->view->color_matrix = malloc_matrix((*fdf)->map_width,
			(*fdf)->map_height);
	ft_set_matrix((*fdf)->view->color_matrix, (*fdf)->map_width,
		(*fdf)->map_height, 0);
	tmp = (*fdf)->map_width;
	(*fdf)->map_fd = fd;
	(*fdf)->matrix = fill_matrix((*fdf)->map_width,
			(*fdf)->map_height, *fdf, -1);
	close(fd);
	(*fdf)->map_width = tmp;
	(*fdf)->changing_map = 0;
}
