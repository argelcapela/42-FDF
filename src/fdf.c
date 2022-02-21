#include "fdf.h"

int main(int argc, char** argv)
{
    // declaring variables
    t_each_dot **map;
    char *map_path;
    
    // checking errors
    if (argc != 2)
    {
        ft_printf("\nPlease follow the model: ./fdf map.fdf\n");
        return (0);
    }
    
    // reading_map
    map_path = ft_strdup(argv[1]);
    map = reading_map(map_path);
    free(map_path);
}
