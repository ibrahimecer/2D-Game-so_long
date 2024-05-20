/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:32:18 by iecer             #+#    #+#             */
/*   Updated: 2024/05/20 12:43:11 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

void	error_massage(char *massage)
{
	ft_printf("%s\n", massage);
	exit(0);
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

void	data_free(t_data *data, int flag, char *massage)
{
	if (data->read_map != NULL)
		free(data->read_map);
	if (flag == 1)
	{
		map_free(data->map->map);
	}
	if (data->map != NULL)
		free(data->map);
	ft_printf("%s\n", massage);
	exit(1);
}

int	mlx_exit(t_data *data, char *massage)
{
	if (data->tex.win)
		mlx_destroy_window(data->tex.mlx, data->tex.win);
	if (data->tex.coin)
		mlx_destroy_image(data->tex.mlx, data->tex.coin);
	if (data->tex.player)
		mlx_destroy_image(data->tex.mlx, data->tex.player);
	if (data->tex.bground)
		mlx_destroy_image(data->tex.mlx, data->tex.bground);
	if (data->tex.exit)
		mlx_destroy_image(data->tex.mlx, data->tex.exit);
	if (data->tex.wall)
		mlx_destroy_image(data->tex.mlx, data->tex.wall);
	return (data_free(data, 1, massage), 1);
}

int	win_close(t_data *data)
{
	mlx_exit(data, "Exit");
	return (1);
}
