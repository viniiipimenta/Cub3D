/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:20:37 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/18 18:21:26 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img	*get_wall_texture(t_game *cub)
{
	float	cos;
	float	sin;

	cos = fabs(cub->ray.cos);
	sin = fabs(cub->ray.sin);
	if (!is_wall(cub->ray.x_pos, cub->ray.y_pos - sin, cub))
		return (cub->texture.east);
	if (!is_wall(cub->ray.x_pos, cub->ray.y_pos + sin, cub))
		return (cub->texture.west);
	if (!is_wall(cub->ray.x_pos + cos, cub->ray.y_pos, cub))
		return (cub->texture.north);
	if (!is_wall(cub->ray.x_pos - cos, cub->ray.y_pos, cub))
		return (cub->texture.south);
	return (cub->texture.black);
}

int	get_texture_color(t_img *texture, int texture_y, t_game *cub)
{
	float	x;
	float	y;
	int		texture_x;

	x = cub->ray.x_pos;
	y = cub->ray.y_pos;
	if (!is_wall(x, y, cub))
		return (0x00000000);
	texture_x = (int)(texture->width * (x + y)) % texture->width;
	return (get_texture_pixel_color(texture_x, texture_y, texture));
}

float	get_wall_start(int wall_height)
{
	return (HEIGHT / 2 - wall_height);
}

void	handle_texture(int ray_count, int wall_height, t_game *cub)
{
	float	v[3];
	int		y;
	int		color;
	t_img	*texture;

	texture = get_wall_texture(cub);
	v[0] = ((float)wall_height * 2) / (float)texture->height;
	v[1] = get_wall_start(wall_height);
	y = 0;
	while (y < texture->height)
	{
		color = get_texture_color(texture, y, cub);
		v[2] = v[1] + v[0];
		while (v[1] < v[2])
		{
			if (v[1] >= 0 && v[1] < (float)HEIGHT)
				set_pixel_color(ray_count, v[1], color, cub);
			v[1]++;
		}
		v[1] = v[2];
		y++;
	}
}