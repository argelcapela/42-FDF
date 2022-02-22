#include "../../../fdf.h"

int  **malloc_matrix(int width, int height)
{
    int i;
    int **matrix;

    i = -1;
    matrix = (int **) ft_calloc(width, sizeof(int *));
    while (++i < width)
        matrix[i] = (int *) ft_calloc(height, sizeof(int));
    return (matrix);
}