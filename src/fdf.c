#include "fdf.h"

int main(int argc, char** argv)
{
    // declaring variables
    int **matrix;
    char *map_path;
    
    // checking errors
    if (argc != 2)
    {
        ft_printf("\nPlease follow the model: ./fdf map.fdf\n");
        return (0);
    }
    
    // reading_map
    map_path = ft_strdup(argv[1]);
    matrix = reading_map(map_path);


    // cleaning leaks
    //ft_free_ptr((void *) map_path);
    //ft_free_ptr((void *) matrix);
}
