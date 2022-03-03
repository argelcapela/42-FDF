/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// "It controls the visualization of the map on the screen."
typedef struct s_dot
{
	float	Xi;
	float	Yi;
	float	Xf;
	float	Yf;
	float	Zi;
	float	Zf;
}			t_dot;

// "It controls the visualization of the map on the screen."
typedef struct s_view
{
	int		color;
	float	move_x;
	float	move_y;
	float	scale;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		isometric;
	int		conic;
}			t_view;

// "It represents the own window and fdf software." 
typedef struct s_fdf
{
	int     amount_of_maps;
	int		c_map;
	char	*c_map_path;
	char	*c_map_name;
	char	**all_maps_path;

	int		window_width;
	int		window_height;
	int		map_width;
	int		map_height;
	int		**matrix;
	void 	*mlx_ptr;
	void	*win_ptr;
	t_view	*view;
}	        t_fdf;

#endif