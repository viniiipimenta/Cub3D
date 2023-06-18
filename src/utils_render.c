/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:03:35 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/18 18:05:42 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

int is_wall(int x, int y, t_game *cub)
{
    if (x < 0 || x >= cub->map.height)
        return (0);
    if (y < 0 || y >= cub->map.width)
        return (0);
    return (cub->map.array[x][y] == '1');
}