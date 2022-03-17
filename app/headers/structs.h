/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:45 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*--------------------------------------------------
   "It represents a image file (png, jpg etc) 
	converted to xpm, to be drawed on screen."
---------------------------------------------------*/
typedef struct s_image
{
	float	x;
	float	y;
	int		width;
	int		height;
	char	*path;
	void	*ptr;
}			t_image;

/*--------------------------------------------------
   "It represents the image that we 
   generate on screen."
---------------------------------------------------*/
typedef struct s_img
{
	int		pixel_bits;
	int		size_line;
	int		endian;
	char	*buffer;
}			t_img;

/*--------------------------------------------------
   "It represents each pixel we 
   draw inside the image."
---------------------------------------------------*/
typedef struct s_dot
{
	float	xi;
	float	xf;
	float	yi;
	float	yf;
	float	zi;
	float	zf;
	int		color;
}			t_dot;

/*--------------------------------------------------
   "It represents a rectangle to be drawed."
---------------------------------------------------*/
typedef struct s_rectangle
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		color;
}			t_rectangle;

/*--------------------------------------------------
   "It controls the visualization of the
   map on the screen."
---------------------------------------------------*/
typedef struct s_view
{
	float	x_origin;
	float	y_origin;
	int		mouse_rotate;
	int		new_color1;
	int		changing_color;
	int		**color_matrix;
	int		color;
	float	move_x;
	float	move_y;
	float	scale;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	u_map_width;
	float	u_map_height;
	int		isometric;
	int		free_rotation;
	float	depth_scale;
}			t_view;

/*--------------------------------------------------
   "It represents the fdf software." 
---------------------------------------------------*/
typedef struct s_fdf
{
	int		hint_box;
	char	**hb_msgs;
	int		hb_width;
	void	*ptr_img;
	t_img	*img;
	int		changing_map;
	int		amount_of_maps;
	int		c_map;
	char	*c_map_path;
	char	*c_map_name;
	char	**all_maps_path;
	int		window_width;
	int		window_height;
	int		map_width;
	int		map_height;
	int		**matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_fd;
	int		f_alloc;
	t_view	*view;
}	t_fdf;

#endif
