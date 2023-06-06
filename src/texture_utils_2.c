/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:15:35 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/06 13:17:04 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_north(char *key)
{
	return (ft_strncmp(key, "NO", 2) == 0 && ft_strlen(key) == 2);
}

int	is_south(char *key)
{
	return (ft_strncmp(key, "SO", 2) == 0 && ft_strlen(key) == 2);
}

int	is_west(char *key)
{
	return (ft_strncmp(key, "WE", 2) == 0 && ft_strlen(key) == 2);
}

int	is_east(char *key)
{
	return (ft_strncmp(key, "EA", 2) == 0 && ft_strlen(key) == 2);
}

int	is_duplicate_key(char *key, t_game *cub)
{
	if (is_north(key) && cub->texture.north)
		return (1);
	if (is_south(key) && cub->texture.south)
		return (1);
	if (is_west(key) && cub->texture.west)
		return (1);
	if (is_east(key) && cub->texture.east)
		return (1);
	if (is_floor(key) && cub->texture.floor != -1)
		return (1);
	if (is_ceiling(key) && cub->texture.ceiling != -1)
		return (1);
	return (0);
}