/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_on_mouse_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:55:40 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:55:43 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

int	on_mouse_down(int button, int x, int y, t_fdf *fdf)
{
	if (x && y && button)
	{
		if (button == 4 || button == 5)
		{
			if (button == 4)
				fdf->view->scale += 5;
			else if (button == 5)
				fdf->view->scale -= 5;
			rerender(fdf);
		}
	}
	return (0);
}
