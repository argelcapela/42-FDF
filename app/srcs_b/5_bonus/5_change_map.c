/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_change_map.c			                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

static void	get_amount_of_maps_and_map_paths(t_fdf *fdf)
{
	int		y;
	int		*amount;
	FILE	*count;
	FILE	*ls;

	amount = malloc(sizeof(int *));
	count = popen("ls ./maps | wc -l", "r");
	ls = popen("ls ./maps", "r");
	y = -1;
	fscanf(count, "%d", amount);
	fdf->amount_of_maps = *amount;
	fdf->all_maps_path = malloc_char_matrix(*amount, 15);
	while (++y < *amount)
		fscanf(ls, "%s", fdf->all_maps_path[y]);
	pclose(ls);
	pclose(count);
	ft_free_ptr((void *) &amount);
}

void	change_map(char **argv, t_fdf *fdf)
{
	int		i;
	int		len;

	get_amount_of_maps_and_map_paths(fdf);
	fdf->c_map_path = ft_printf_to_var("%s", argv[1]);
	fdf->c_map_name = ft_substr(fdf->c_map_path, 5, ft_strlen(fdf->c_map_path));
	i = -1;
	while (++i < fdf->amount_of_maps)
	{
		len = ft_strlen(fdf->all_maps_path[i]);
		if (ft_strncmp(fdf->all_maps_path[i], fdf->c_map_name, len) == 0)
		{
			fdf->c_map = i;
			break ;
		}
	}
}
