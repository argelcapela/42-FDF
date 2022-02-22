#ifndef FDF_H
#define FDF_H 

/* lib.a = original libft , libft++, get-next-line and ft_printf */
#include "vendor/libs/libs.h"


/*################################################### 
#													#
#	 constants and structures:              		#
#													#
###################################################*/

// white
#define color0 0xffffff 

// AC green
#define color1 0x000000

/* t_each_dot
#
#   "This struct..."
#
#   x:
#   y:
#   z:
#   is_last:
#   color:
#   scale:
#   shift_x:
#   shift_y:
#   is_isometric:
#   angle:
#   win_x:
#   win_y:
#   *mlx_ptr:
#   *win_ptr:
#
#
*/

typedef struct
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
}   t_each_dot;


/*################################################### 
#													#
#	 utilitaries:                             		#
#													#
###################################################*/
void    print_matrix(int **matrix, int width, int height);


/*################################################### 
#													#
#	 1) reading map:                          		#
#													#
###################################################*/
int getting_height(char  *path);
int getting_width(char  *path);
int  **malloc_matrix(int width, int height);
int **malloc_read_map_and_fill_matrix(int width, int height, char *path);

int  **reading_map(char *map_path);

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