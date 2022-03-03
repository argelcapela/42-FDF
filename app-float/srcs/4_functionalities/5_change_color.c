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

void    change_color(int key, t_fdf **fdf)
{
	int rgb[3];
       char *str;
    if (key == KEY_C)
	{
		(*fdf)->view->changing_color = 1;
        rgb[0] = rand() % 254;
        rgb[1] = rand() % 254;
        rgb[2] = rand() % 254;
        str = ft_printf_to_var("0x%x%x%x", rgb[0], rgb[1], rgb[2]);
        sscanf(str,"%x", &(*fdf)->view->new_color1);        
	}
}