/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:42:49 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 18:43:38 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../fdf.h"

/*--------------------------------------------------
   "It counts how many lines the map.fdf file has."
---------------------------------------------------*/

int	getting_height(char *path)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_free_ptr((void *) &line);
		height++;
		line = get_next_line(fd);
	}
	ft_free_ptr((void *) &line);
	close(fd);
	return (height);
}
