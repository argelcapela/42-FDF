/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move.c				                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

int	on_mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->view->mouse_translate == 1)
	{
		fdf->view->mouse_x = x;
		fdf->view->mouse_y = y;
		rerender(fdf);
	}
	return (0);
}
