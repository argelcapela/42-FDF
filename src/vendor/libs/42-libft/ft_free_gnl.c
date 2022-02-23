/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:11:26 by acapela-          #+#    #+#             */
/*   Updated: 2022/01/22 03:57:06 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../libs.h"

void	ft_free_gnl(char **line, int fd)
{
 	while (*line)
    {
        ft_free_ptr((void *) &(*line));
        *line = get_next_line(fd);
    }
}
