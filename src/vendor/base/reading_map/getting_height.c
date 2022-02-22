#include "../../../fdf.h"

/*--------------------------------------------------

    "It counts how many lines the map file has."

                    char   *path:
                    int  *height:
                    int       fd:
   open(path, flag, buffer_size):
                       close(fd):

---------------------------------------------------*/

int getting_height(char  *path)
{
    int height;
    int fd;

    height = 0;
    fd = open(path, O_RDONLY);
    while (get_next_line(fd) > 0)
        height++;
    close(fd);
    return (height);
}