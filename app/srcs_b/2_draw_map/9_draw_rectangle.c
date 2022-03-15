/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_draw_rectangle.c	                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void	draw_rectangle(t_rectangle *rect, t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= rect->height)
	{
		x = -1;
		while (++x <= rect->width)
		{
			draw_pixel_in_image(&fdf, x, y,
				rect->color);
		}
	}
}
