#include "../../../fdf.h"


int **reading_map(char *path)
{
    int     **matrix;
    int     height;
    int     width;

    height = 0;
    width  = 0;
    height = getting_height(path);
    width = getting_width(path);
    matrix = malloc_read_map_and_fill_matrix(width, height, path);
    print_matrix(matrix, width, height);
    return (matrix);
}
