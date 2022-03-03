/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:45:54 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 18:56:51 by acapela-         ###   ########.fr       */
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
	int tmp;

	(*fdf)->map_width = get_width((*fdf)->c_map_path);
	(*fdf)->map_height = get_height((*fdf)->c_map_path);
	tmp = (*fdf)->map_width;
	fd = open((*fdf)->c_map_path, O_RDONLY);
	(*fdf)->matrix = fill_matrix((*fdf)->map_width, (*fdf)->map_height, fd, -1);
	print_matrix((*fdf)->matrix, (*fdf)->map_width, (*fdf)->map_height, (*fdf)->c_map_path);
	close(fd);
	(*fdf)->map_width = tmp;
	
}

