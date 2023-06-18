/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:14:56 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/18 18:19:22 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_pixel_color(int x, int y, int color, t_game *cub)
{
	char	*dst;
	t_img	*img;

	img = &cub->window_image;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_texture_pixel_color(int x, int y, t_img *img)
{
	char	*result;

	result = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)result);
}

int	is_within_ray_limit(int x, int y, t_game *cub)
{
	float	delta_x;
	float	delta_y;
	float	distance;

	delta_x = x - cub->player.x_pos - 0.5;
	delta_y = y - cub->player.y_pos - 0.5;
	distance = sqrt(powf(delta_x, 2.) + powf(delta_y, 2.));
	return (distance < cub->ray.limit);
}

int	has_ray_reached_limit(t_game *cub)
{
	if (!is_within_ray_limit(cub->ray.x_pos, cub->ray.y_pos, cub))
		return (1);
	return (is_wall(cub->ray.x_pos, cub->ray.y_pos, cub));
}