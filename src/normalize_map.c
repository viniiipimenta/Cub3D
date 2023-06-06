/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:37:23 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/06 13:38:05 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_normalized(char *original_row, t_game *cub)
{
	char	*result;
	int		i;
	int		row_length;

	row_length = ft_strlen(original_row);
	result = malloc(sizeof(char) * (cub->map.width + 1));
	i = 0;
	while (i < cub->map.width)
	{
		if (i >= row_length)
			result[i] = ' ';
		else
			result[i] = original_row[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	normalize_map(t_game *cub)
{
	char	**normalized_map;
	int		i;

	normalized_map = malloc(sizeof(char *) * (cub->map.height + 1));
	i = 0;
	while (i < cub->map.height)
	{
		normalized_map[i] = get_normalized(cub->map.array[i], cub);
		i++;
	}
	normalized_map[i] = NULL;
	matrix_free(cub->map.array);
	cub->map.array = normalized_map;
}