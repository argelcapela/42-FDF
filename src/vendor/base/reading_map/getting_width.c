#include "../../../fdf.h"

int getting_width(char  *path)
{
    int width;
    char **line;
    int fd;

    width = 0;
    fd = open(path, O_RDONLY);
    line = ft_split(get_next_line(fd), ' ');  
    while (line[width])
        width++;
    close(fd);
    return (width);
}