/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void    add_move(int key, t_fdf **fdf)
{
	if (key == KEY_DOWN)
		(*fdf)->view->move_y += 10;
	if (key == KEY_UP)
		(*fdf)->view->move_y -= 10;
	if (key == KEY_LEFT)
		(*fdf)->view->move_x -= 10;
	if (key == KEY_RIGHT)
		(*fdf)->view->move_x += 10;
}