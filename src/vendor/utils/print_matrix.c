#include "../../fdf.h"

void    print_matrix(int **matrix, int width, int height)
{
    int     x;
    int     y;

    x = -1;
    y = -1;
    while (++y < height)
    {
        while (++x < width)
            ft_printf("%3d", matrix[x][y]);
        x = -1;
        ft_printf("\n");
    }
}