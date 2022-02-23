/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char** argv)
{
    int **matrix;
    char *map_path;
    int width;
    int height;
    
    width = 0;
    height = 0;
    if (argc != 2)
    {
        ft_printf("\nPlease follow the model: ./fdf map.fdf\n");
        return (0);
    }
    map_path = argv[1];
    matrix = reading_map(map_path, &width, &height);
    while ((width - 1) >= 0)
        ft_free_ptr((void *) &matrix[--width]);  
    ft_free_ptr((void *) &matrix);
}
