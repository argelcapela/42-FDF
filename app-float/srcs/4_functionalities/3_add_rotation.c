/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void    add_rotation(int key, t_fdf **fdf)
{
	// x
	if (key == KEY_W)
		(*fdf)->view->angle_x += (5 * ONE_DEGREE);
	if (key == KEY_S)
		(*fdf)->view->angle_x -= (5 * ONE_DEGREE);

	// y
	if (key == KEY_A)
		(*fdf)->view->angle_y -= (5 * ONE_DEGREE);
	if (key == KEY_D)
		(*fdf)->view->angle_y += (5 * ONE_DEGREE);
	
	// z
	if (key == KEY_Q)
		(*fdf)->view->angle_z += (5 * ONE_DEGREE);
	if (key == KEY_E)
		(*fdf)->view->angle_z -= (5 * ONE_DEGREE);
	
}