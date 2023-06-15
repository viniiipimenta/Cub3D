/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:13 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/15 16:06:43 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_for_open_walls(t_game *cub)
{
	char	**map;
	int		px;
	int		py;

	px = cub->player.x_pos;
	py = cub->player.y_pos;
	map = dup_matrix(cub->map.array);
	map[px][py] = '0';
	check_for_open_wall(map, px, py, cub);
	matrix_free(map);
}

void	set_player_props(t_game *cub, int x, int y, char player_dir)
{
	cub->player.dir = player_dir;
	cub->player.x_pos = x;
	cub->player.y_pos = y;
}

void	check_player_exist(t_game *cub)
{
	int	players_count;
	int	i;
	int	j;

	players_count = 0;
	i = 0;
	while (cub->map.array[i])
	{
		j = 0;
		while (cub->map.array[i][j])
		{
			if (is_player_cell(cub->map.array[i][j]))
			{
				set_player_props(cub, i, j, cub->map.array[i][j]);
				players_count++;
			}
			j++;
		}
		i++;
	}
	if (players_count != 1)
		exit_cub("Invalid number of players", cub);
}

void	check_invalid_char(t_game *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.array[i])
	{
		j = 0;
		while (cub->map.array[i][j])
		{
			if (!is_valid_cell(cub->map.array[i][j]))
				exit_cub("Invalid char in map", cub);
			j++;
		}
		i++;
	}
}

void    map_validation(t_game *cub)
{
    check_invalid_char(cub);
    check_player_exist(cub);
    check_for_open_walls(cub);
}