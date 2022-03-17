/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_draw_pixel_in_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:04 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	draw_pixel_in_image(t_fdf **fdf, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= (*fdf)->window_width
		|| y < 0 || y >= (*fdf)->window_height)
		return ;
	pixel = (*fdf)->img->buffer + x * (32 / 8) + y * (*fdf)->img->size_line;
	pixel[0] = (color) & 0xFF;
	pixel[1] = (color >> 8) & 0xFF;
	pixel[2] = (color >> 16) & 0xFF;
	pixel[3] = (color >> 24);
}
