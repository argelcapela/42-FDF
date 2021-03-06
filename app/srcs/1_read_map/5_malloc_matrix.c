/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_malloc_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:45:20 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:53:19 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

/*--------------------------------------------------
   "Taking the width and height of a map.fdf,
	this function, allocate memory and return
	a matrix [width, height], also called
	2d array."
---------------------------------------------------*/

int	**malloc_matrix(int width, int height)
{
	int		i;
	int		**matrix;

	i = -1;
	matrix = (int **) malloc(width * sizeof(int *) + 1);
	while (++i < width)
		matrix[i] = (int *) malloc(height * sizeof(int) + 1);
	return (matrix);
}

char	**malloc_char_matrix(int width, int height)
{
	int		i;
	char	**matrix;

	i = -1;
	matrix = (char **) malloc(width * sizeof(char *) + 1);
	while (++i < width)
		matrix[i] = (char *) malloc(height * sizeof(char) + 1);
	return (matrix);
}

char	**malloc_char_array(int size)
{
	char	**matrix;

	matrix = (char **) ft_calloc(size + 1, sizeof(char *));
	return (matrix);
}
