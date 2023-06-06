/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:12:49 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/06 13:12:50 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_floor(char *key)
{
	return (ft_strncmp(key, "F", 1) == 0 && ft_strlen(key) == 1);
}

int	is_ceiling(char *key)
{
	return (ft_strncmp(key, "C", 1) == 0 && ft_strlen(key) == 1);
}

int	is_color_texture(char *key)
{
	return (is_floor(key) || is_ceiling(key));
}

int	is_cardinal_direction(char *key)
{
	return (is_north(key) || is_south(key) || is_west(key) || is_east(key));
}

int	is_valid_key(char *key)
{
	return (is_cardinal_direction(key) || is_color_texture(key));
}