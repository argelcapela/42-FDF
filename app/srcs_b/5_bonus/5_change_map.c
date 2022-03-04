/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_for_change_map.c                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_bonus.h"

void    change_map(char **argv, t_fdf *fdf)
{
	int *amount_of_maps;

	amount_of_maps = (int *) malloc(sizeof(int)); 
	FILE *count = popen("ls ./maps | wc -l", "r");
	fscanf(count, "%d", amount_of_maps);
	char **all_maps_path = malloc_char_matrix(*amount_of_maps, 15);
	FILE *ls = popen("ls ./maps", "r");
	int y = 0;
	while (fscanf(ls, "%s", all_maps_path[y]) == 1 && y < *amount_of_maps)
		y++;
	fdf->amount_of_maps = *amount_of_maps;
	fdf->c_map_path = ft_printf_to_var("%s", argv[1]);
	fdf->c_map_name = ft_substr(fdf->c_map_path, 5, ft_strlen(fdf->c_map_path));
	fdf->all_maps_path = all_maps_path;
	int	 i = 0;
	while (i < *amount_of_maps)
	{
		if (ft_strncmp(fdf->all_maps_path[i], fdf->c_map_name, ft_strlen(fdf->all_maps_path[i])) == 0)
		{
			fdf->c_map = i;
			break;
		}
		i++;
	}
}