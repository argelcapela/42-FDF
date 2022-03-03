/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_projection.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void    change_projection(int key, t_fdf **fdf)
{
    if (key == KEY_I && (*fdf)->view->isometric == 1)
		  (*fdf)->view->isometric = 0;
    else if (key == KEY_I && (*fdf)->view->isometric == 0)
		  (*fdf)->view->isometric = 1;
}