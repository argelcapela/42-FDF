/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_fill_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:32 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

#define TOKEN "X"

static void	get_just_hexa(char *cel, char **just_hexa,
	char **hexa_before_token)
{
	char	*hexa_tokenized;
	char	*bn;

	(*just_hexa) = ft_substr(cel, ft_indexof(cel, ',') + 4, ft_strlen(cel));
	if (ft_strchr((*just_hexa), '\n'))
	{
		bn = ft_chr_to_str('\n', 1);
		hexa_tokenized = ft_str_replace((*just_hexa), bn, TOKEN);
		(*hexa_before_token) = ft_substr(hexa_tokenized,
				0, ft_indexof(cel, 'X'));
		ft_free_ptr((void *) &hexa_tokenized);
		ft_free_ptr((void *) &bn);
	}
	else
		(*hexa_before_token) = (*just_hexa);
}

static void	get_and_parse_hexa_color(char *cel,
		char **just_hexa, int *depth_value)
{
	char	*char_depth_value;
	char	*hexa_final;
	char	*hexa_before_token;

	get_just_hexa(cel, just_hexa, &hexa_before_token);
	char_depth_value = ft_substr(cel, 0, ft_indexof(cel, ','));
	*depth_value = ft_atoi(char_depth_value);
	ft_free_ptr((void *) &char_depth_value);
	if (ft_strlen(hexa_before_token) != 6)
	{
		hexa_final = ft_str_merge(hexa_before_token,
				ft_chr_to_str('0', 6 - ft_strlen(hexa_before_token)));
		(*just_hexa) = hexa_final;
	}
	else
		(*just_hexa) = hexa_before_token;
}

static int	get_map_color(int x, int y, char *cel, t_fdf *fdf)
{
	int		depth_value;
	int		*h_int;
	char	*just_hexa;
	char	*cel_start;

	cel_start = cel;
	depth_value = 0;
	while (*cel++)
		*cel = ft_toupper(*cel);
	cel = cel_start;
	if (ft_strchr(cel, 'X'))
	{
		just_hexa = NULL;
		get_and_parse_hexa_color(cel, &just_hexa, &depth_value);
		if (ft_strlen(just_hexa) == 6)
			h_int = ft_hexatoi(just_hexa);
		else
			h_int = 0;
		fdf->view->color_matrix[x][y] = *h_int;
		ft_free_ptr((void *) &h_int);
		ft_free_ptr((void *) &just_hexa);
	}
	else
		depth_value = ft_atoi(cel);
	return (depth_value);
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
			ft_free_ptr((void *) &split[x]);
		}
		ft_free_ptr((void *) &split[x]);
		x = -1;
		ft_free_ptr((void *) &line);
		ft_free_ptr((void *) &split);
	}
	line = get_next_line(fdf->map_fd);
	ft_free_ptr((void *) &line);
	return (matrix);
}
