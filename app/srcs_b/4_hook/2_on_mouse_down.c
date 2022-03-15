/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_down.c				                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
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
