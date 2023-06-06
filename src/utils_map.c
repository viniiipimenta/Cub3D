/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:35:22 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/06 13:28:22 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_texture_key(char *line, t_game *cub)
{
	char	**split;
	char	*result;

	split = ft_split(line, ' ');
	if (matrix_len(split) != 2)
	{
		matrix_free(split);
		exit_cub("Exactly two positions in texture line", cub);
	}
	result = ft_strdup(split[0]);
	if (!is_valid_key(result) || is_duplicate_key(result, cub))
	{
		free(result);
		matrix_free(split);
		exit_cub("You send either invalid or duplicated keys", cub);
	}
	matrix_free(split);
	return (result);
}

char	*get_texture_value(char *line, t_game *cub)
{
	char	**split;
	char	*result;

	split = ft_split(line, ' ');
	if (matrix_len(split) != 2)
	{
		matrix_free(split);
		exit_cub("Exactly two positions in texture line", cub);
	}
	result = ft_strdup(split[1]);
	matrix_free(split);
	return (result);
}

void	texture_path(char *key, char *path, t_game *cub)
{
	if (is_north(key))
		cub->texture.north = img_load(path, cub);
	if (is_south(key))
		cub->texture.south = img_load(path, cub);
	if (is_west(key))
		cub->texture.west = img_load(path, cub);
	if (is_east(key))
		cub->texture.east = img_load(path, cub);
	free(key);
	free(path);
}

void	color_string(char *key, char *string, t_game *cub)
{
	if (is_floor(key))
		cub->texture.floor = get_color_from_string(string, cub);
	if (is_ceiling(key))
		cub->texture.ceiling = get_color_from_string(string, cub);
	free(key);
	free(string);
}

void	handle_texture_line(char *line, t_game *cub)
{
	char	*key;
	char	*value;

	key = get_texture_key(line, cub);
	value = get_texture_value(line, cub);
	if (is_cardinal_direction(key))
		return (texture_path(key, value, cub));
	return (color_string(key, value, cub));
}