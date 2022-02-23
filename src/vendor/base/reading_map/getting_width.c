/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:44:24 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 18:44:35 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../fdf.h"

/*--------------------------------------------------
   "It counts how many numbers, at least, one
   line of the map.fdf has."
---------------------------------------------------*/

int	getting_width(char *path)
{
	int		width;
	char	**split;
	char	*line;
	int		fd;

	width = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	while (split[width])
	{
		ft_free_ptr((void *) &split[width]);
		width++;
	}
	while (line)
	{
		ft_free_ptr((void *) &line);
		line = get_next_line(fd);
	}
	ft_free_ptr((void *) &split);
	ft_free_ptr((void *) &line);
	close(fd);
	return (width);
}
