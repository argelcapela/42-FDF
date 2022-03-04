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

void 	decide_pixel_color(t_dot *dot, t_fdf *fdf);

void    draw_pixel_in_image(t_fdf **fdf, int x, int y, int color);

void    draw_line(t_dot *dot, t_fdf *fdf);

void 	draw_wireframe(t_fdf *fdf);

void 	fill_wireframe(t_fdf *fdf);

void 	align_center(t_dot *dot, t_fdf *fdf);

void 	render(t_fdf **fdf);

int		rerender(t_fdf *fdf);

/*###################################################
#													#
#	 3_projection		                    	    #
#													#
###################################################*/

void    isometric(float *x, float *y, float *z);

// (bonus)
void    conic(float *x, float *y, float *z);

void    none_projection(float *x, float *y, float *z);

/*###################################################
#													#
#	 4_hook (bonus)		                          	#
#													#
###################################################*/

int		on_release_key(int key, t_fdf *fdf);

int		on_mouse_down(t_fdf *fdf);

int		on_mouse_move(t_fdf *fdf);

int		on_destroy(t_fdf *fdf);

/*###################################################
#													#
#	 5_tools (bonus)	                          	#
#													#
###################################################*/

void    enable_tools(t_dot **dot, t_fdf **fdf);

void    zoom(t_dot **dot, t_fdf **fdf);

void    zoom_on_mouse_scroll (int key, t_fdf **fdf);

void    translate(t_dot *dot, t_fdf *fdf);

void    translate_on_left_mouse_down_move (t_dot **dot, t_fdf **fdf);

void    rotate_x(t_dot *dot, t_fdf *fdf);

void    rotate_y(t_dot *dot, t_fdf *fdf);

void    rotate_z(t_dot *dot, t_fdf *fdf);

void 	rotate_xyz_on_right_mouse_down_move (t_dot **dot, t_fdf **fdf);

void    change_color(t_fdf *fdf);

void    change_map(char **argv, t_fdf **fdf);

void    hint_box( t_fdf **fdf);

#endif

/*###################################################
													
	 	bye bye.

		Never forget!

		Jesus loves you!

		You will have a marvelous future!

		XD                          				
													
###################################################*/
