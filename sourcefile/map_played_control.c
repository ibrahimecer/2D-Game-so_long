/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_played_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:02 by iecer             #+#    #+#             */
/*   Updated: 2024/05/06 16:50:29 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

char	**virtual_map_create(t_data *data, int x, int y)
{
	char	**vmap;

	vmap = (char **)malloc(sizeof(char *) * (data->map->map_h + 1));
	if (!vmap)
		data_free(data, 1, "Error\nMalloc failed.");
	while (y < data->map->map_h)
	{
		vmap[y] = (char *)malloc(data->map->map_w + 1);
		if (!vmap[y])
		{
			map_free(vmap);
			data_free(data, 1, "Error\nMalloc failed.");
		}
		x = 0;
		while (x < data->map->map_w)
		{
			vmap[y][x] = '0';
			++x;
		}
		vmap[y][x] = '\0';
		++y;
	}
	vmap[y] = NULL;
	return (vmap);
}

void	map_check_played(t_data *data, char **vmap, int x, int y)
{
	if (data->map->map[y][x] == 'C' || data->map->map[y][x] == 'E')
		data->temp--;
	if (data->map->map[y - 1][x] != '1' && vmap[y - 1][x] == '0')
	{
		vmap[y - 1][x] = '1';
		map_check_played(data, vmap, x, y - 1);
	}
	if (data->map->map[y][x - 1] != '1' && vmap[y][x - 1] == '0')
	{
		vmap[y][x - 1] = '1';
		map_check_played(data, vmap, x - 1, y);
	}
	if (data->map->map[y + 1][x] != '1' && vmap[y + 1][x] == '0')
	{
		vmap[y + 1][x] = '1';
		map_check_played(data, vmap, x, y + 1);
	}
	if (data->map->map[y][x + 1] != '1' && vmap[y][x + 1] == '0')
	{
		vmap[y][x + 1] = '1';
		map_check_played(data, vmap, x + 1, y);
	}
}

void	played_control(t_data *data)
{
	char	**vmap;

	vmap = virtual_map_create(data, 0, 0);
	map_check_played(data, vmap, data->px, data->py);
	if (data->temp != 0)
	{
		map_free(vmap);
		data_free(data, 1,
			"Error\nCollectibles cannot be collected. Map is incorrect.");
	}
	map_free(vmap);
}
