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

/* lib.a = original libft , libft++, get-next-line and ft_printf */
# include "vendor/libs/libs.h"

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
	int		width;
	int		height;
	int		**matrix;

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
int		getting_height(char *path);
int		getting_width(char *path);
int		**malloc_matrix(int width, int height);
int		**fill_matrix(int width, int height, int fd, int x);
int		**reading_map(int argc, char **argv);

/*###################################################
#													#
#	 2) drawing_isometric_projection:	            #
#													#
###################################################*/

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
