/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_get_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:44:24 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:53:16 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

static char	*parse_spaces(char *line)
{
	int		i;
	int		end_s;
	char	*tmp;

	i = ft_strlen(line);
	end_s = 0;
	while (line[i] == ' ' || line[i] == '\n')
	{
		if (line[i] == ' ')
			end_s++;
		i--;
	}
	if (end_s != 0)
	{
		tmp = ft_substr(line, 0, i - 1);
		ft_free_ptr((void *) &line);
	}
	else
		return (line);
	return (tmp);
}

int	get_width(char *path)
{
	int		width;
	char	**split;
	char	*line;
	int		fd;

	width = 0;
	fd = open(path, O_RDONLY);
	line = parse_spaces(get_next_line(fd));
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
