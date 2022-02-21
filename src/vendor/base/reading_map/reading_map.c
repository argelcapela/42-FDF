#include "../../../fdf.h"

void    allocating_memory_for_map_matrix(int fd_file_having_map, t_each_dot **MAP_MATRIX)
{
    // declaring variables
    char    **line_matrix;
    int     x; // how_many_columns_numbers_per_line_without_space
    int     y; // how_many_lines

    // initializing
    x = 1;

    // read 1st line
    ft_printf("%s", get_next_line(fd_file_having_map));
    line_matrix = ft_split(get_next_line(fd_file_having_map), 32);

    // count how many columns, numbers per line without spaces (' ')
    ft_printf("%d", ft_strlen(line_matrix));
    //x = ft_strlen(line_matrix[0]);

    // count how many lines
    while (get_next_line(fd_file_having_map) > 0)
    y++;

    /* malloc */
        // y - rows
        MAP_MATRIX = (t_each_dot **) malloc(sizeof(t_each_dot *) * y + 1);
        y -= 1; // removing one to don't conflict with the '\0'

        // x - cols
        //while (y > 0)
        /*{
            MAP_MATRIX[y] = (t_each_dot *)malloc(sizeof(t_each_dot) 
            * x + 1);
            y--;
        }*/

    // closind fd
    close(fd_file_having_map);
}

void    reading_map_file_and_filling_map_matrix()
{
    // declaring variables
    int fd_file_having_map;
}


t_each_dot **reading_map(char *map_path)
{
    // declarinng variables
    t_each_dot **MAP_MATRIX;
    int fd_file_having_map;

    // opening file_having_map
    fd_file_having_map = open(map_path, O_RDONLY, 0);

    /*********************************************************************************** 
        Allocate enough memory in MAP_MATRIX:
            - count how many numbers avoiding the spaces we have in a line.
            - count how many lines the file has.
            - malloc this in MAP_MATRIX.
    ************************************************************************************/
    allocating_memory_for_map_matrix(fd_file_having_map, &MAP_MATRIX);

    /***********************************************************************************  
        1.Iterate each line having a counter that represents how many lines it file has. 
        2.Each line has a line_matrix , created by spliting line by ' '. 
        3.Filling each part of MAP_MATRIX[x , y].parameter = value:
            - x: line.
            - y: column.
            - parameter: option of struct.
            - value: value read from file, or received from counters.
        Return MAP_MATRIX read to be used.
    ************************************************************************************/
    //MAP_MATRIX = reading_map_file_and_filling_map_matrix();

    return (MAP_MATRIX);
}