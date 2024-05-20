/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:46:10 by iecer             #+#    #+#             */
/*   Updated: 2024/05/20 12:50:36 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	line_control(char **map)
{
	size_t	line_length;
	int		line_count;
	int		j;

	line_length = ft_strlen(map[0]);
	line_count = 0;
	j = 0;
	while (map[line_count])
	{
		if (ft_strlen(map[line_count]) != line_length)
			return (0);
		if (map[line_count][0] != '1'
			|| map[line_count][line_length - 1] != '1')
			return (0);
		++line_count;
	}
	while (map[line_count - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[line_count - 1][j] != '1')
			return (0);
		++j;
	}
	return (1);
}

void	map_read(char *map, t_data *data)
{
	int		len;
	int		fd;

	len = map_len(map);
	data->read_map = (char *)malloc(sizeof(char) * (len + 1));
	if (!data->read_map)
		error_massage("Error\nMalloc failed.");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		data_free(data, 0, "Error\nMap unreadable.");
	if (read(fd, data->read_map, len) <= 0)
	{
		close(fd);
		data_free(data, 0, "Error\nRead failed.");
	}
	close(fd);
	data->read_map[len] = '\0';
	if (newline_control(data->read_map) == 0)
		data_free(data, 0, "Error\nThe map is wrong.");
	if (elements_control(data->read_map) == 0)
		data_free(data, 0, "Error\nThe map is wrong.");
	if (elements_counter(data->read_map, 'P') != 1
		|| elements_counter(data->read_map, 'E') != 1)
		data_free(data, 0, "Error\nThe map is wrong.");
}

char	**map_build(char *map)
{
	char	**map_array;

	if (map == NULL)
		return (NULL);
	map_array = ft_split(map, '\n');
	if (!map_array)
		return (NULL);
	if (line_control(map_array) == 0)
		return (map_free(map_array), NULL);
	return (map_array);
}

void	map_init(t_data *data, char *map)
{
	data->map = NULL;
	map_read(map, data);
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		data_free(data, 0, "Error\nMap not generated.");
	data->map->map = map_build(data->read_map);
	if (!data->map->map)
		data_free(data, 0, "Error\nData not generated.");
	map_w_h_counter(data);
	player_position(data);
	data->cc = elements_counter(data->read_map, 'C');
	if (data->cc == 0)
		data_free(data, 1, "Error\nNone collectibles");
	data->temp = data->cc + 1;
	data->mc = 0;
	free(data->read_map);
	data->read_map = NULL;
}
