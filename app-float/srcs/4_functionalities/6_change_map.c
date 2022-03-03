/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void    change_map(int key, t_fdf **fdf)
{
    if (key == KEY_LESS && (*fdf)->c_map >= 1)
    {
        (*fdf)->c_map -= 1;
        (*fdf)->c_map_path = ft_printf_to_var("maps/%s", (*fdf)->all_maps_path[(*fdf)->c_map]);
    }
    if (key == KEY_BIGGER && (*fdf)->c_map <= (*fdf)->amount_of_maps)
    {
        (*fdf)->c_map += 1;
        (*fdf)->c_map_path = ft_printf_to_var("maps/%s", (*fdf)->all_maps_path[(*fdf)->c_map]);
    }
}