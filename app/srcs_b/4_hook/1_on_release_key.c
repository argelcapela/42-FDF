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

#include "../../headers/fdf_bonus.h"

static void zoom_translate_and_rotate_keys(int key, t_fdf **fdf)
{
	if (key == KEY_PLUS || key == KEY_PLUS2)
		(*fdf)->view->scale += 5;
	if (key == KEY_MINUS || key ==  KEY_MINUS2)
		(*fdf)->view->scale -= 5;
	if (key == KEY_UP)
		(*fdf)->view->move_y -= 10;
	if (key == KEY_DOWN)
		(*fdf)->view->move_y += 10;
	if (key == KEY_LEFT)
		(*fdf)->view->move_x -= 10;
	if (key == KEY_RIGHT)
		(*fdf)->view->move_x += 10;
		
	if (key == KEY_W)
		(*fdf)->view->angle_x += (5 * ONE_DEGREE);
	if (key == KEY_S)
		(*fdf)->view->angle_x -= (5 * ONE_DEGREE);
	if (key == KEY_Q)
		(*fdf)->view->angle_y -= (5 * ONE_DEGREE);
	if (key == KEY_E)
		(*fdf)->view->angle_y += (5 * ONE_DEGREE);
	if (key == KEY_A)
		(*fdf)->view->angle_z += (5 * ONE_DEGREE);
	if (key == KEY_D)
		(*fdf)->view->angle_z -= (5 * ONE_DEGREE);

	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D || key == KEY_Q || key == KEY_E)
	    (*fdf)->view->free_rotation = 1;
}

static void change_color_map_and_hint_box_keys(int key, t_fdf **fdf)
{
	if (key == KEY_C)
        change_color(*fdf);
		
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
	if (key == KEY_H && (*fdf)->hint_box == 1)
		(*fdf)->hint_box = 0;
	else if (key == KEY_H && (*fdf)->hint_box == 0)
		(*fdf)->hint_box = 1;
}

static void exit_program_and_change_projection_keys(int key, t_fdf **fdf)
{
    if (key == KEY_ESC)
	{
        mlx_loop_end((*fdf)->mlx_ptr);
	}
	
	if (key == KEY_I && (*fdf)->view->isometric == 1)
		  (*fdf)->view->isometric = 0;
    else if (key == KEY_I && (*fdf)->view->isometric == 0)
		  (*fdf)->view->isometric = 1;
}

int	on_release_key(int key, t_fdf *fdf)
{
	ft_printf("#%d#\n", key);
	zoom_translate_and_rotate_keys(key, &fdf);
	change_color_map_and_hint_box_keys(key, &fdf);
	exit_program_and_change_projection_keys(key, &fdf);
	rerender(fdf);
	return (0);
}
