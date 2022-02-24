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

/* libft */
# include "vendor/libs/libs.h"

/* minilibx */
# include "mlx.h"

// sin, cos
# include <math.h>

/*###################################################
#													#
#	 constants and structures:              		#
#													#
###################################################*/

// white
# define COLOR0 0xffffff

// AC green
# define COLOR1 0x000000

/*
 "It struct fdf, represents the own window and fdf software."
*/ 
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


	void 	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

/*###################################################
#													#
#	 utilitaries:                             		#
#													#
###################################################*/
void	print_matrix(int **matrix, int width, int height);
void 	error(int argc, char **argv);
void    bresenham(float x, float y, float x1, float y1, t_fdf *data);

/*###################################################
#													#
#	 1) reading map:                          		#
#													#
###################################################*/
void    initialize_t_fdf(t_fdf **fdf);
int		getting_height(char *path);
int		getting_width(char *path);
int		**malloc_matrix(int width, int height);
int		**fill_matrix(int width, int height, int fd, int x);
void	reading_map(int argc, char **argv, t_fdf **fdf);

/*###################################################
#													#
#	 2) drawing_isometric_projection:	            #
#													#
###################################################*/
void 	draw(t_fdf *fdf);
void    isometric_projection(float *x, float *y, int z, t_fdf *fdf);	


/*###################################################
#													#
#	 3) adding_3d:                            	    #
#													#
###################################################*/

/*###################################################
#													#
#	 4) adding_bonus:                          	    #
#													#
###################################################*/

#endif
