/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:11:26 by acapela-          #+#    #+#             */
/*   Updated: 2022/01/22 03:57:06 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../libs.h"

void	ft_free_matrix(int ***matrix, int rows)
{
	int i;

	i = 0;
	while (i < (rows - 1))
	{
		free(*(*matrix + i));
		i++;
	}
	free (*(matrix));
}
