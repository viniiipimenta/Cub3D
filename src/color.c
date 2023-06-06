/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:19:58 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/06 13:25:46 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	invalid_color(char *string, char **parts, t_game *cub)
{
	free(string);
	matrix_free(parts);
	return (exit_cub("Invalid color", cub));
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	is_string_numeric(char *string)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(string);
	while (i < len)
	{
		if (!ft_isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_color_parts_valid(char **parts, char *string)
{
	int	i;

	if (count_char_in_string(string, ',') != 2)
		return (0);
	if (!parts || matrix_len(parts) != 3)
		return (0);
	i = 0;
	while (i < matrix_len(parts))
	{
		if (!is_string_numeric(parts[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_color_from_string(char *string, t_game *cub)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(string, ',');
	if (!is_color_parts_valid(parts, string))
		return (invalid_color(string, parts, cub));
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (invalid_color(string, parts, cub));
	matrix_free(parts);
	return (rgb_to_int(r, g, b));
}