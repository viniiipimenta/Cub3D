/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:57:44 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/15 16:06:25 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_valid_position(char **map, int x, int y)
{
	if (!map[x] || !map[x][y])
		return (0);
	return (map[x][y] == '1' || map[x][y] == '0');
}

void	check_for_open_wall(char **map, int px, int py, t_game *cub)
{
	if (!is_valid_position(map, px, py))
	{
		matrix_free(map);
		exit_cub("Open wall found from player position.", cub);
	}
	if (map[px][py] == '1')
		return ;
	map[px][py] = '1';
	check_for_open_wall(map, px + 1, py, cub);
	check_for_open_wall(map, px - 1, py, cub);
	check_for_open_wall(map, px, py + 1, cub);
	check_for_open_wall(map, px, py - 1, cub);
}

int	is_player_cell(char map_cell)
{
	return (ft_strchr("NSEW", map_cell) != 0);
}

int	is_valid_cell(char map_cell)
{
	return (ft_strchr("NSEW 01", map_cell) != 0);
}