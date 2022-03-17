/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_get_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:42:49 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:25 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

int	get_height(char *path)
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
