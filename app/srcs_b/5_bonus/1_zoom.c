/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_zoom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:54:49 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:55 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void	set_initial_scale(int index, t_fdf **fdf)
{
	if ((index >= 1 && index <= 4) || (index >= 6 && index <= 9))
		(*fdf)->view->scale = 20;
	else if ((index >= 13 && index <= 18) || index == 5)
		(*fdf)->view->scale = 15;
	else if (index >= 10 && index <= 11)
		(*fdf)->view->scale = 1;
	else if (index == 0 || index == 12 || (index >= 18 && index <= 21))
		(*fdf)->view->scale = 4;
	(*fdf)->view->isometric = 0;
	(*fdf)->view->angle_x = 0;
	(*fdf)->view->angle_y = 0;
	(*fdf)->view->angle_z = 0;
	(*fdf)->view->move_x = 0;
	(*fdf)->view->move_y = 0;
}

void	zoom(t_dot **dot, t_fdf **fdf)
{
	float	s;

	s = (*fdf)->view->scale;
	(*dot)->xi *= s;
	(*dot)->yi *= s;
	(*dot)->xf *= s;
	(*dot)->yf *= s;
}
