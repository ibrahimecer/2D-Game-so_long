/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:57:08 by iecer             #+#    #+#             */
/*   Updated: 2024/05/20 12:40:07 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include "../minilibx/mlx.h"

int	moving(int keycode, t_data *data)
{
	if (keycode == ESC)
		mlx_exit(data, "Exit");
	else if (keycode == W && data->map->map[data->py - 1][data->px] != '1')
		data->py--;
	else if (keycode == A && data->map->map[data->py][data->px - 1] != '1')
		data->px--;
	else if (keycode == S && data->map->map[data->py + 1][data->px] != '1')
		data->py++;
	else if (keycode == D && data->map->map[data->py][data->px + 1] != '1')
		data->px++;
	else
		return (0);
	ft_printf("Movements : %d\n", ++data->mc);
	if (data->map->map[data->py][data->px] == 'C')
	{
		--data->cc;
		data->map->map[data->py][data->px] = '0';
	}
	if (data->map->map[data->py][data->px] == 'E' && data->cc == 0)
		mlx_exit(data, "Yes! You win! Congratulations!");
	return (0);
}

int	main(int arc, char **arg)
{
	t_data	data;

	if (arc == 2)
	{
		map_extension_control(arg[1]);
		map_init(&data, arg[1]);
		data_init(&data);
		played_control(&data);
		map_render(&data);
		mlx_hook(data.tex.win, 2, 0, moving, &data);
		mlx_hook(data.tex.win, 17, 0, win_close, &data);
		mlx_loop_hook(data.tex.mlx, put_player, &data);
		mlx_loop(data.tex.mlx);
	}
	else
		error_massage("Error\nArgument entered wrong.");
}
