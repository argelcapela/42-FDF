/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:55:56 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:00 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	isometric(float *x, float *y, float *z)
{
	float	tmp_x;

	tmp_x = *x;
	*x = (tmp_x - *y) * cos(THIRTY_DEGREES);
	*y = (tmp_x + *y) * sin(THIRTY_DEGREES) - *z;
}
