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

/*typedef struct
{
	float   x;
	float   y;
	float   z;
	int     is_last;
	int     color;
	int     scale;
	int     shift_x;
	int     shift_y;
	int     is_isometric;
	double  angle;
	int     win_x;
	int     win_y;
	void    *mlx_ptr;
	void    *win_ptr;
}   t_each_dot;*/

/*###################################################
#													#
#	 utilitaries:                             		#
#													#
###################################################*/
void	print_matrix(int **matrix, int width, int height);

/*###################################################
#													#
#	 1) reading map:                          		#
#													#
###################################################*/
int		getting_height(char *path);
int		getting_width(char *path);
int		**malloc_matrix(int width, int height);
int		**fill_matrix(int width, int height, int fd, int x);
int		**reading_map(char *path, int *x, int *y);

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
