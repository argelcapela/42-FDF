/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_draw_image.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void draw_image (t_image *image, t_fdf *fdf)
{
    image->ptr = mlx_xpm_file_to_image(fdf->mlx_ptr, image->path, &image->width, &image->height);
}