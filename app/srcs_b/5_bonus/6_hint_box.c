/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_hint_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:55:15 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

static void	draw_hb_bg(t_fdf *fdf)
{
	t_rectangle	*rect;

	rect = (t_rectangle *) malloc(sizeof(t_rectangle));
	rect->x = 0;
	rect->y = 0;
	rect->width = fdf->hb_width;
	rect->height = 900;
	rect->color = AC_GREEN2;
	draw_rectangle(rect, fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->ptr_img, 0, 0);
	ft_free_ptr((void *) &rect);
}

static void	draw_logos(t_fdf *fdf)
{
	t_image	*logo;
	t_image	*fdf_logo;

	logo = (t_image *) malloc(sizeof(t_image));
	logo->width = 10;
	logo->height = 10;
	logo->path = ft_strdup("assets/logo-small.xpm");
	logo->ptr = mlx_xpm_file_to_image(fdf->mlx_ptr, logo->path,
			&logo->width, &logo->height);
	mlx_put_image_to_window(fdf->mlx_ptr,
		fdf->win_ptr, logo->ptr, 30, fdf->window_height - 200);
	mlx_destroy_image(fdf->mlx_ptr, logo->ptr);
	ft_free_ptr((void *) &logo->path);
	ft_free_ptr((void *) &logo);
	fdf_logo = (t_image *) malloc(sizeof(t_image));
	fdf_logo->width = 15;
	fdf_logo->height = 15;
	fdf_logo->path = ft_strdup("assets/fdf-bonus-logo.xpm");
	fdf_logo->ptr = mlx_xpm_file_to_image(fdf->mlx_ptr, fdf_logo->path,
			&fdf_logo->width, &fdf_logo->height);
	mlx_put_image_to_window(fdf->mlx_ptr,
		fdf->win_ptr, fdf_logo->ptr, 50, 10);
	mlx_destroy_image(fdf->mlx_ptr, fdf_logo->ptr);
	ft_free_ptr((void *) &fdf_logo->path);
	ft_free_ptr((void *) &fdf_logo);
}

static void	print_msgs_1(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		10, 240, GREEN, "Hotkeys:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 260, WHITE, "w/s - Rotate x Axle");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 280, WHITE, "a/d - Rotate y Axle");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 300, WHITE, "q/e - Rotate z Axle");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 320, WHITE, "UP/DOWN/LEFT/RIGHT ARROW - Translate");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 340, WHITE, "+/-/Scroll Mouse - zoom in, zoom out");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 360, WHITE, "i - Isometric/Paralell Perspective");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 380, WHITE, "< / > - Change Map");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 400, WHITE, "c - Change Color1 Randomly");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 420, WHITE, "h - Show/Hide Hint box on screen");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 440, WHITE, "r - Reset");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 460, WHITE, "f/g - Decrease/Increase Map Depth");
}

static void	print_msgs_2(t_fdf *fdf)
{
	fdf->hb_msgs[0] = ft_printf_to_var
		("Alpha/x: %d deg", (int)((fdf->view->angle_x * 180) / 3.14));
	fdf->hb_msgs[1] = ft_printf_to_var
		("Beta/y: %d deg", (int)((fdf->view->angle_y * 180) / 3.14));
	fdf->hb_msgs[2] = ft_printf_to_var
		("Gamma/z: %d deg", (int)((fdf->view->angle_z * 180) / 3.14));
	fdf->hb_msgs[3] = ft_printf_to_var("[%d/%d] - %s", fdf->c_map + 1,
			fdf->amount_of_maps, fdf->all_maps_path[fdf->c_map]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		10, 520, GREEN, "Monitor:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 540, WHITE, fdf->hb_msgs[0]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 560, WHITE, fdf->hb_msgs[1]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 580, WHITE, fdf->hb_msgs[2]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 620, WHITE, fdf->hb_msgs[3]);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		20, 600,
		WHITE, fdf->hb_msgs[4]);
}

void	hint_box(t_fdf **fdf)
{	
	(*fdf)->hb_msgs = malloc_char_array(5);
	if ((*fdf)->hb_msgs[5])
		ft_free_ptr((void *) &(*fdf)->hb_msgs[4]);
	else if ((*fdf)->view->isometric == 1)
		(*fdf)->hb_msgs[4] = ft_strdup("Current Projection: Isometric");
	else if ((*fdf)->view->isometric == 0)
		(*fdf)->hb_msgs[4] = ft_strdup("Current Projection: Paralell");
	draw_wireframe(fdf);
	draw_hb_bg((*fdf));
	draw_logos((*fdf));
	print_msgs_1((*fdf));
	print_msgs_2((*fdf));
	mlx_string_put((*fdf)->mlx_ptr, (*fdf)->win_ptr,
		50, 173, WHITE, "'Fil de Fer / Wireframe'");
	free_array_char((*fdf));
	ft_free_ptr((void *) &(*fdf)->c_map_path);
}
