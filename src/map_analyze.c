/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:12:05 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/06 13:39:00 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	map_texture_analyze(char *path, t_game *cub)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	count = 0;
	line = gnl_util(fd);
	if (!line)
		exit_cub("Empty file", cub);
	while (line)
	{
		if (count > 6 && !ft_strlen(line))
			exit_cub("Empty line inside map", cub);
		if (ft_strlen(line))
			handle_line(line, count++, cub);
		free(line);
		line = gnl_util(fd);
	}
	if (!matrix_len(cub->map.array))
		exit_cub("Map is empty", cub);
	close(fd);
}

void	map_analyze(char *path, t_game *cub)
{
	map_texture_analyze(path, cub);
	normalize_map(cub);
}