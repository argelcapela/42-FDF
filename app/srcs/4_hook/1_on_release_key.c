/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_events_when_press_keys.c                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

static void	exit_program(int key, t_fdf **fdf)
{
	if (key == KEY_ESC)
		mlx_loop_end((*fdf)->mlx_ptr);
}

int	on_release_key(int key, t_fdf *fdf)
{
	ft_printf("%d\n", key);
	exit_program(key, &fdf);
	rerender(fdf);
	return (0);
}
