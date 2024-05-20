/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:22:49 by iecer             #+#    #+#             */
/*   Updated: 2024/05/20 12:01:00 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	map_extension_control(char *map)
{
	size_t	len;
	int		fd;

	len = ft_strlen(map);
	if (!(map[len - 1] == 'r' && map[len - 2] == 'e'
			&& map[len - 3] == 'b' && map[len - 4] == '.'))
		error_massage("Error\nThe map extension should be the .ber extension.");
	else
	{
		fd = open(map, O_RDONLY);
		if (fd == -1)
			error_massage("Error\nThe map failed to open");
		close(fd);
	}
}

int	map_len(char *map)
{
	int		len;
	int		fd;
	char	chr;
	int		i;

	i = 1;
	len = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_massage("Error\nOpen failed");
	while (len >= 0)
	{
		i = read(fd, &chr, 1);
		if (i <= 0)
			break ;
		len++;
	}
	close (fd);
	return (len);
}

int	newline_control(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (0);
		++i;
	}
	return (1);
}

int	elements_control(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			return (0);
		++i;
	}
	return (1);
}

int	elements_counter(char *map, char elements)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		if (map[i] == elements)
			++counter;
		++i;
	}
	return (counter);
}
