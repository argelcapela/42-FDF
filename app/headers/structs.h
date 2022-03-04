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

// "It represents the image that we generate on screen."
typedef struct s_img
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
		
}			t_img;

// "It represents each pixel we draw inside the image."
typedef struct s_dot
{
	float	Xi;
	float	Yi;
	float	Xf;
	float	Yf;
	float	Zi;
	float	Zf;
	int		color;
}			t_dot;

// "It controls the visualization of the map on the screen."
typedef struct s_view
{
	int		new_color1;
	int		new_color2;
	int		changing_color;
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

// "It represents the fdf software." 
typedef struct s_fdf
{
	int		hint_box;
	void	*ptr_img;
	t_img	*img;
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