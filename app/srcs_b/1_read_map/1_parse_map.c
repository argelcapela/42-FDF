/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:14 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

void	parse_map(int argc, char **argv)
{
	int		fd;
	char	*b;

	b = malloc(2 + 1);
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 && !argv[1])
	{
		ft_putstr_fd("\033[31;1m\n\nPLEASE FOLLOW \
THE MODEL: ./fdf maps/map.fdf\n\033[0m\n\n", 1);
		exit(0);
	}
	else if ((read(fd, b, 0) < 0))
	{
		ft_putstr_fd("\033[31;1m\n\nINVALID MAP PATH, \
PLEASE TRY AGAIN!\n\033[0m\n\n", 1);
		exit(0);
	}
	else if (read(fd, b, 1) == 0)
	{
		ft_putstr_fd("\033[31;1m\n\nEMPTY MAP OR \
MAP DOESN'T HAVE AT LEAST 1 BREAK LINE,\nPLEASE,\
FIX IT OR ENTER OTHER VALID MAP!\n\033[0m\n\n", 1);
		exit(0);
	}
	else
	{
		ft_putstr_fd("\033[1;32m\n\nLoading \
map...\n\033[0m\n", 1);
	}
	ft_free_ptr((void *) &b);
}
