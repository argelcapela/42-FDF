/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hint_map.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void    hint_box(t_fdf **fdf)
{
	char *current_map;
	char *perspective;
	
	current_map = ft_printf_to_var("[%d/%d] - %s",(*fdf)->c_map + 1, (*fdf)->amount_of_maps + 1,(*fdf)->all_maps_path[(*fdf)->c_map]);
	if ((*fdf)->view->isometric == 0)
		perspective = ft_strdup("No Perspective");
	else if ((*fdf)->view->isometric == 1)
		perspective = ft_strdup("Isometric Perspective");
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 10, (*fdf)->window_height - 10, WHITE, current_map);
    mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 10, 20, WHITE, "w/s - Rotate X");
 	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 10, 40, WHITE, "a/d - Rotate Y");
 	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 10, 60, WHITE, "q/e - Rotate Z");
 	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 10, 80, WHITE, "UP/DOWN/LEFT/RIGHT ARROW  - Move");
 	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 10, 100, WHITE, "i   - Enable/Disable Isometric Perspective");
 	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 10, 120, WHITE, "< / > - Change Map");
 	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, 10, 140, WHITE, "SHIFT - Change Color Randomly");
 	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr, (*fdf)->window_width - 150, (*fdf)->window_height - 10, WHITE, perspective);
	ft_free_ptr((void *) &perspective);
}