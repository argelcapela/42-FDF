/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_pixel_color.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	decide_pixel_color(t_dot *dot, t_fdf *fdf)
{
	int	color;

	if (fdf->view->changing_color == 0)
		color = AC_GREEN1;
	else if (fdf->view->changing_color == 1)
		color = fdf->view->new_color1;
	if (dot->Zi != 0 || dot->Zf != 0)
	{
		if (fdf->view->color_matrix[(int)dot->Xi][(int)dot->Yi] != 0)
			fdf->view->color = fdf->view->color_matrix
			[(int)dot->Xi][(int)dot->Yi];
		else if (fdf->view->color_matrix[(int)dot->Xi][(int)dot->Yi] == 0)
			fdf->view->color = color;
	}
	else
		fdf->view->color = 0xffffff;
}
