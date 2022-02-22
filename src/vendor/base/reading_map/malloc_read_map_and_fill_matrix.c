#include "../../../fdf.h"

int **malloc_read_map_and_fill_matrix(int width, int height, char *path)
{
    int     fd;
    int     x;
    int     y;
    char    **line;
    int     **matrix;

    x  = -1;
    y  = -1;
    fd = open(path, O_RDONLY);
    matrix = malloc_matrix(width, height);
    while (++y < height)
    {
        line = ft_split(get_next_line(fd), ' ');
        while (++x < width)
        {
            matrix[x][y] = ft_atoi(line[x]);
        }
        x = -1;
        ft_free_ptr((void *) line);
        //ft_free_ptr((void *) split);
    }
    close (fd);
    return (matrix);
}