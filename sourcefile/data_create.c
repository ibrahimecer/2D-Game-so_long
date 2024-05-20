/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:58:44 by iecer             #+#    #+#             */
/*   Updated: 2024/05/20 12:05:17 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

void	map_w_h_counter(t_data *data)
{
	int	map_height;

	map_height = 0;
	while (data->map->map[map_height])
		++map_height;
	data->map->map_h = map_height;
	data->map->map_w = ft_strlen(data->map->map[0]);
}

void	player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
			{
				data->px = x;
				data->py = y;
			}
			++x;
		}
		++y;
	}
}

void	data_init(t_data *data)
{
	int	x;
	int	y;

	data->tex.mlx = mlx_init();
	if (!data->tex.mlx)
		data_free (data, 1, "Error\nMlx failed.");
	data->tex.win = mlx_new_window (data->tex.mlx, data->map->map_w * PIXEL,
			data->map->map_h * PIXEL, "game");
	data->tex.coin = mlx_xpm_file_to_image (data->tex.mlx,
			"textures/coin.xpm", &x, &y);
	data->tex.bground = mlx_xpm_file_to_image (data->tex.mlx,
			"textures/bground.xpm", &x, &y);
	data->tex.player = mlx_xpm_file_to_image (data->tex.mlx,
			"textures/player.xpm", &x, &y);
	data->tex.wall = mlx_xpm_file_to_image (data->tex.mlx,
			"textures/wall.xpm", &x, &y);
	data->tex.exit = mlx_xpm_file_to_image (data->tex.mlx,
			"textures/exit.xpm", &x, &y);
	if (!data->tex.player || !data->tex.coin || !data->tex.exit
		|| !data->tex.wall || !data->tex.bground || !data->tex.win)
		mlx_exit (data, "Error\nFailed to create file.");
}

void	map_render(t_data *data)
{
	int	i;
	int	j;

	mlx_clear_window(data->tex.mlx, data->tex.win);
	i = -1;
	while (++i < data->map->map_h)
	{
		j = -1;
		while (++j < data->map->map_w)
		{
			if (data->map->map[i][j] == '1')
				mlx_put_image_to_window(data->tex.mlx, data->tex.win,
					data->tex.wall, j * PIXEL, i * PIXEL);
			else
				mlx_put_image_to_window(data->tex.mlx, data->tex.win,
					data->tex.bground, j * PIXEL, i * PIXEL);
			if (data->map->map[i][j] == 'E')
				mlx_put_image_to_window(data->tex.mlx, data->tex.win,
					data->tex.exit, j * PIXEL, i * PIXEL);
			else if (data->map->map[i][j] == 'C')
				mlx_put_image_to_window(data->tex.mlx, data->tex.win,
					data->tex.coin, j * PIXEL, i * PIXEL);
		}
	}
}

int	put_player(t_data *data)
{
	map_render(data);
	mlx_put_image_to_window(data->tex.mlx, data->tex.win, data->tex.player,
		data->px * PIXEL, data->py * PIXEL);
	return (0);
}
