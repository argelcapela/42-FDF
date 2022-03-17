/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_translate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:57 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	translate(t_dot *dot, t_fdf *fdf)
{
	dot->xi += fdf->view->move_x;
	dot->yi += fdf->view->move_y;
	dot->xf += fdf->view->move_x;
	dot->yf += fdf->view->move_y;
}
