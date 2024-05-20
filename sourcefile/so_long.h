/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:00:33 by iecer             #+#    #+#             */
/*   Updated: 2024/05/14 12:11:36 by iecer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PIXEL	100
# define W		13
# define A		0
# define S		1
# define D		2
# define ESC	53

typedef struct s_map
{
	char	**map;
	int		map_w;
	int		map_h;
}	t_map;

typedef struct s_tex
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*coin;
	void	*wall;
	void	*bground;
	void	*exit;
}	t_tex;

typedef struct s_data
{
	int		cc;
	int		px;
	int		py;
	int		temp;
	int		mc;
	char	*read_map;
	t_tex	tex;
	t_map	*map;
}	t_data;

void	error_massage(char *massage);
void	map_extension_control(char *map);
int		map_len(char *map);
void	map_read(char *map, t_data *data);
int		newline_control(char *map);
int		elements_control(char *map);
int		elements_counter(char *map, char elements);
char	**map_build(char *map);
int		line_control(char **map);
void	map_free(char **map);
void	map_init(t_data *data, char *map);
void	data_free(t_data *data, int flag, char *massage);
void	map_w_h_counter(t_data *data);
void	player_position(t_data *data);
void	map_render(t_data *data);
void	data_init(t_data *data);
int		put_player(t_data *data);
int		mlx_exit(t_data *data, char *massage);
int		win_close(t_data *data);
char	**virtual_map_create(t_data *data, int x, int y);
void	map_check_played(t_data *data, char **vmap, int x, int y);
void	played_control(t_data *data);

#endif
