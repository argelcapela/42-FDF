/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_on_release_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:55:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:55:34 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

static void	reset(t_fdf **fdf)
{
	(*fdf)->view->depth_scale = 1;
	(*fdf)->view->angle_x = 0;
	(*fdf)->view->angle_y = 0;
	(*fdf)->view->angle_z = 0;
	set_initial_scale((*fdf)->c_map, fdf);
	(*fdf)->view->isometric = 1;
	(*fdf)->view->changing_color = 0;
}

static void	keyboard_set_3(int key, t_fdf **fdf)
{
	if (key == KEY_PLUS || key == KEY_PLUS2)
		(*fdf)->view->scale += 5;
	if (key == KEY_MINUS || key == KEY_MINUS2)
		(*fdf)->view->scale -= 5;
	if (key == KEY_UP)
		(*fdf)->view->move_y -= 10;
	if (key == KEY_DOWN)
		(*fdf)->view->move_y += 10;
	if (key == KEY_LEFT)
		(*fdf)->view->move_x -= 10;
	if (key == KEY_RIGHT)
		(*fdf)->view->move_x += 10;
	if (key == KEY_I && (*fdf)->view->isometric == 1)
	{
		reset(fdf);
		(*fdf)->view->isometric = 0;
	}
	else if (key == KEY_I && (*fdf)->view->isometric == 0)
		(*fdf)->view->isometric = 1;
}

static void	keyboard_set_2(int key, t_fdf **fdf)
{
	if (key == KEY_F)
		(*fdf)->view->depth_scale -= (0.1);
	if (key == KEY_G)
		(*fdf)->view->depth_scale += (0.1);
	if (key == KEY_W)
		(*fdf)->view->angle_x += (5 * ONE_DEGREE);
	if (key == KEY_S)
		(*fdf)->view->angle_x -= (5 * ONE_DEGREE);
	if (key == KEY_A)
		(*fdf)->view->angle_y -= (5 * ONE_DEGREE);
	if (key == KEY_D)
		(*fdf)->view->angle_y += (5 * ONE_DEGREE);
	if (key == KEY_E)
		(*fdf)->view->angle_z += (5 * ONE_DEGREE);
	if (key == KEY_Q)
		(*fdf)->view->angle_z -= (5 * ONE_DEGREE);
	if (key == KEY_ESC)
		mlx_loop_end((*fdf)->mlx_ptr);
	if (key == KEY_R)
		reset(fdf);
}

static void	keyboard_set_1(int key, t_fdf **fdf)
{
	if (key == KEY_C)
		change_color(*fdf);
	if (key == KEY_LESS && (*fdf)->c_map > 0)
	{
		(*fdf)->changing_map = 1;
		(*fdf)->c_map -= 1;
		set_initial_scale((*fdf)->c_map, fdf);
		reset(fdf);
	}
	else if (key == KEY_BIGGER && (*fdf)->c_map < (*fdf)->amount_of_maps - 1)
	{
		(*fdf)->changing_map = 1;
		(*fdf)->c_map += 1;
		set_initial_scale((*fdf)->c_map, fdf);
		reset(fdf);
	}
	if (key == KEY_H && (*fdf)->hint_box == 1)
		(*fdf)->hint_box = 0;
	else if (key == KEY_H && (*fdf)->hint_box == 0)
		(*fdf)->hint_box = 1;
	(*fdf)->c_map_path = ft_printf_to_var("maps/%s",
			(*fdf)->all_maps_path[(*fdf)->c_map]);
}

int	on_release_key(int key, t_fdf *fdf)
{
	keyboard_set_1(key, &fdf);
	keyboard_set_2(key, &fdf);
	keyboard_set_3(key, &fdf);
	rerender(fdf);
	return (0);
}
