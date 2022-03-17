/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_change_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:55:03 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:55:06 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void	change_color(t_fdf *fdf)
{
	int		rgb[3];
	char	*str;

	fdf->view->changing_color = 1;
	rgb[0] = rand() % 254;
	rgb[1] = rand() % 254;
	rgb[2] = rand() % 254;
	str = ft_printf_to_var("0x%x%x%x", rgb[0], rgb[1], rgb[2]);
	sscanf(str, "%x", &fdf->view->new_color1);
	ft_free_ptr((void *) &str);
}
