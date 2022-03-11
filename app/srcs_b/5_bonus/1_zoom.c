/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_draws.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

int	zoom_on_mouse_scroll(int button, int x, int y, t_fdf *fdf)
{
	if (button && x && y && fdf)
	{
	}
	return (0);
}

void	zoom(t_dot **dot, t_fdf **fdf)
{
	float	s;

	s = (*fdf)->view->scale;
	(*dot)->Xi *= s;
	(*dot)->Yi *= s;
	(*dot)->Xf *= s;
	(*dot)->Yf *= s;
}
