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

/*###################################################
#													#
#	 0_libraries                         			#
#													#
###################################################*/

// 1. libft 
# include "../libs/libft/libft.h"

// 2. minilibx 
# include "../libs/minilibx/mlx.h"

// 3. sin, cos, isometric perspective
# include <math.h>

// 4. structs
# include "structs.h"

// 5. macros
# include "macros.h"

// for test
# include <stdio.h>


/*###################################################
#													#
#	 1_read_map                         			#
#													#
###################################################*/

void	read_map(t_fdf **fdf);

void 	parse_map(int argc, char **argv);

void    init_structs(t_fdf **fdf);

int		get_width(char *path);

int		get_height(char *path);

int		**malloc_matrix(int width, int height);

char	**malloc_char_matrix(int width, int height);

int		**fill_matrix(int width, int height, int fd, int x);

void	print_matrix(int **matrix, int width, int height, char *map_path);

/*###################################################
#													#
#	 2_draw_map  						            #
#													#
###################################################*/

void 	draw_map(t_fdf *fdf);

void    bresenham(t_dot *dot, t_fdf *fdf);

void    link_draws_to_bresenham(t_dot **dot, t_fdf *fdf);

void 	draw_zoom(t_dot *dot, t_fdf *fdf);

void 	draw_move(t_dot *dot, t_fdf *fdf);

void 	draw_rotation_x(t_dot *dot, t_fdf *fdf);

void 	draw_rotation_y(t_dot *dot, t_fdf *fdf);

void 	draw_rotation_z(t_dot *dot, t_fdf *fdf);

void 	draw_projection(t_dot *dot, t_fdf *fdf);

void 	draw_color(t_dot *dot, t_fdf *fdf);

void 	draw_alignment(t_dot *dot, t_fdf *fdf);


/*###################################################
#													#
#	 3_add_projection                          	    #
#													#
###################################################*/

void    add_plane_projection(float *x, float *y, float *z, t_fdf *fdf);

void    add_isometric_projection(float *x, float *y, float *z, t_fdf *fdf);

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

void    change_color(int key, t_fdf **fdf);

void    change_map(int key, t_fdf **fdf);

void    prepare_for_change_map(char **argv, t_fdf **fdf);

void    hint_box(t_fdf **fdf);

#endif

/*###################################################
													
	 	bye bye.

		Never forget!

		Jesus loves you!

		You will have a marvelous future!

		XD                          				
													
###################################################*/
