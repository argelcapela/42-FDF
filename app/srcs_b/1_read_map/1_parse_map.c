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

#include "../../headers/fdf_bonus.h"

static void	leave(char *b)
{
	ft_free_ptr((void *) &b);
	exit(0);
}

static void	parses(int argc, char **argv, char *b, int fd)
{
	if (argc != 2 && !argv[1])
	{
		ft_putstr_fd("\033[31;1m\n\nPLEASE FOLLOW \
THE MODEL: ./fdf maps/map.fdf\n\033[0m\n\n", 1);
		leave(b);
	}
	else if (read(fd, b, 0) < 0)
	{
		ft_putstr_fd("\033[31;1m\n\nINVALID MAP PATH, \
PLEASE TRY AGAIN!\n\033[0m\n\n", 1);
		leave(b);
	}
	else if (read(fd, b, 2) == 0)
	{
		ft_putstr_fd("\033[31;1m\n\nEMPTY MAP OR \
MAP DOESN'T HAVE AT LEAST 1 BREAK LINE,\nPLEASE,\
FIX IT OR ENTER OTHER VALID MAP!\n\033[0m\n\n", 1);
		leave(b);
	}
	else
	{
		ft_putstr_fd("\033[1;32m\n\nLoading \
map...\n\033[0m\n", 1);
		ft_free_ptr((void *) &b);
	}
}

void	parse_map(int argc, char **argv)
{
	int		fd;
	char	*b;

	b = malloc(2 + 1);
	if (b == NULL)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	parses(argc, argv, b, fd);
}
