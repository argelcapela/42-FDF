/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_events_when_press_keys.c                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

int	shoot_events_when_press_keys(int key, t_fdf *fdf)
{
	ft_printf("%d\n", key);
	add_move(key, &fdf);
	add_zoom(key, &fdf);
	add_rotation(key, &fdf);
	change_projection(key, &fdf);
	change_map(key, &fdf);
	change_color(key, &fdf);
	others(key, &fdf);
	render(&fdf);
	return (0);
}