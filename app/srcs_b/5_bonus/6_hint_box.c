/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_hint_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/11 13:10:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

static void	print_header_footer(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		60, 20, WHITE, "********************");	
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		60, 35, WHITE, "* Fil de Fer (FDF) *");	
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		60, 50, WHITE, "********************");	

}

static void	print_msgs_1(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		10, 80, GREEN, "Hotkeys:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 100, WHITE, "w/s - Rotate X Axle");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 120, WHITE, "a/d - Rotate Y Axle");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 140, WHITE, "q/e - Rotate Z Axle");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 160, WHITE, "UP/DOWN/LEFT/RIGHT ARROW/");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 180, WHITE, "Hold Down Left Mouse Click");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 200, WHITE, "and Drag  - Translate");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 220, WHITE, "+/-/Scroll Mouse - Zoom in, Zoom out");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 240, WHITE, "i - Isometric/Paralell Perspective");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 260, WHITE, "< / > - Change Map");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 280, WHITE, "c - Change Color1 Randomly");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 300, WHITE, "h - Show/Hide Text on screen");
}

static void	print_msgs_2(t_fdf *fdf)
{
	fdf->hb_msgs[0] = ft_printf_to_var
		("Alpha/X: %d deg", fdf->view->angle_x);
	fdf->hb_msgs[1] = ft_printf_to_var
		("Beta/Y: %d deg", fdf->view->angle_y);
	fdf->hb_msgs[2] = ft_printf_to_var
		("Gamma/Z: %d deg", fdf->view->angle_z);
	fdf->hb_msgs[3] = ft_printf_to_var("[%d/%d] - %s", fdf->c_map,
			fdf->amount_of_maps, fdf->all_maps_path[fdf->c_map]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		10, 340, GREEN, "Monitor:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 360, WHITE, fdf->hb_msgs[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 380, WHITE, fdf->hb_msgs[1]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 400, WHITE, fdf->hb_msgs[2]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 440, WHITE, fdf->hb_msgs[3]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 420,
		WHITE, fdf->hb_msgs[4]);
}

void	hint_box(t_fdf **fdf)
{	
	(*fdf)->hb_msgs = malloc_char_array(6);
	if ((*fdf)->hb_msgs[4])
		ft_free_ptr((void *) &(*fdf)->hb_msgs[4]);
	if ((*fdf)->view->isometric == 0 && (*fdf)->view->free_rotation == 0)
		(*fdf)->hb_msgs[4] = ft_strdup("Current Projection: None");
	else if ((*fdf)->view->isometric == 1)
		(*fdf)->hb_msgs[4] = ft_strdup("Current Projection: Isometric");
	else if ((*fdf)->view->free_rotation == 1)
		(*fdf)->hb_msgs[4] = ft_strdup("Current Projection: Free Rotation");
	print_header_footer((*fdf));
	print_msgs_1((*fdf));
	print_msgs_2((*fdf));
	free_array_char((*fdf));
}
