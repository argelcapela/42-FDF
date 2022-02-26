/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// libft 
# include "libs/libft/libft.h"

// minilibx 
# include "libs/minilibx/mlx.h"

// sin, cos, isometric perspective
# include <math.h>

// "It represents the own window and fdf software." 
typedef struct
{
	int		window_width;
	int		window_height;
	int		width;
	int		height;
	int		**matrix;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		move_x;
	int		move_y;
	float	rotate_2d;
	float	rotate_3d;
	float	angle;
	int		perspective_3d;
	void 	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

/*###################################################
#													#
#	 1_read_map                         			#
#													#
###################################################*/

void	read_map(int argc, char **argv, t_fdf **fdf);

void 	parse_map(int argc, char **argv);

void    initialize_t_fdf_struct(t_fdf **fdf);

int		get_width(char *path);

int		get_height(char *path);

int		**malloc_matrix(int width, int height);

int		**fill_matrix(int width, int height, int fd, int x);

void	print_matrix(int **matrix, int width, int height, char *map_path);

/*###################################################
#													#
#	 2_draw_map  						            #
#													#
###################################################*/

void 	draw_map(t_fdf *fdf);

void    bresenham(float x, float y, float x1, float y1, t_fdf *data);

/*###################################################
#													#
#	 3_add_projection                          	    #
#													#
###################################################*/

void    add_isometric_projection(float *x, float *y, int z, t_fdf *fdf);

void    add_conic_projection(float *x, float *y, int z, t_fdf *fdf);

/*###################################################
#													#
#	 4_functionalities                          	#
#													#
###################################################*/

int		detect_input(int key, t_fdf *fdf);

void    add_zoom(int key, t_fdf **fdf);

void    add_move(int key, t_fdf **fdf);

void    add_rotation(int key, t_fdf **fdf);

void    change_projection(int key, t_fdf **fdf);

void    change_map(int key, t_fdf **fdf);

void    hint_box(int key, t_fdf **fdf);

#endif

/* 
	
	bye bye.

	Never forget!

	Jesus loves you!

	You will have a marvelous future!

	XD

 */
