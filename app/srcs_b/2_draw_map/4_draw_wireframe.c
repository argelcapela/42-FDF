/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_draw_wireframe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

static void	update_dots_cordinates(float x, float y, t_dot **dot, int d)
{
	if (d == 1)
	{
		(*dot)->xi = x;
		(*dot)->yi = y;
		(*dot)->xf = x + 1;
		(*dot)->yf = y;
	}
	if (d == 2)
	{
		(*dot)->xi = x;
		(*dot)->yi = y;
		(*dot)->xf = x;
		(*dot)->yf = y + 1;
	}
}

static void	draw_xy(int x, int y, t_dot	*dot, t_fdf **fdf)
{
	if (x < (*fdf)->map_width - 1)
	{
		update_dots_cordinates(x, y, &dot, 1);
		draw_line(dot, (*fdf));
	}
	if (y < (*fdf)->map_height - 1)
	{
		update_dots_cordinates(x, y, &dot, 2);
		draw_line(dot, (*fdf));
	}
}

void	draw_wireframe(t_fdf **fdf)
{
	int		x;
	int		y;
	t_dot	*dot;

	y = -1;
	dot = (t_dot *) malloc(sizeof(t_dot));
	dot->zi = 0;
	dot->zf = 0;
	(*fdf)->view->u_map_width = 0;
	(*fdf)->view->u_map_height = 0;
	while (++y < (*fdf)->map_height)
	{
		x = -1;
		while (++x < (*fdf)->map_width)
			draw_xy(x, y, dot, fdf);
	}
	ft_free_ptr((void *) &dot);
}
