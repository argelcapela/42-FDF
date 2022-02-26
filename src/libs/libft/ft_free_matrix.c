/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matriz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:11:26 by acapela-          #+#    #+#             */
/*   Updated: 2022/01/22 03:57:06 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void    ft_free_matrix(void ***matrix, int width)
{
     while ((width - 1) >= 0)
	 	ft_free_ptr((void *) &(*matrix)[--width]);
	ft_free_ptr((void *) (*matrix));
}