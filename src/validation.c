/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:06:08 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/15 23:08:10 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	close(fd);
	return (fd > 0);
}

int check_extention(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (ft_strncmp(map + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int validation_file(int argc, char **argv)
{
    if (argc != 2)
        return (error_msg("Try: ./cub3D maps/<map>.cub"));
    if (!check_extention(argv[1]))
        return (error_msg("Extention invalid, use .cub"));
    if (!check_file(argv[1]))
        return (error_msg("Can not open this file"));
    return (1);
}