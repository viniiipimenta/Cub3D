/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:17:11 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/06 13:32:21 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	handle_map_line(char *line, t_game *cub)
{
	cub->map.array = matrix_push(cub->map.array, line);
	cub->map.width = max(cub->map.width, ft_strlen(line));
	cub->map.height++;
}

char	*gnl_util(int fd)
{
	char	*tmp;
	char	*line;

	tmp = get_next_line(fd);
	line = ft_strtrim(tmp, "\n");
	free(tmp);
	return (line);
}

int	count_char_in_string(char *string, char to_find)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (string && string[i])
	{
		if (string[i] == to_find)
			result++;
		i++;
	}
	return (result);
}

void	handle_line(char *line, int count, t_game *cub)
{
	if (count < 6)
		return (handle_texture_line(line, cub));
	return (handle_map_line(line, cub));
}