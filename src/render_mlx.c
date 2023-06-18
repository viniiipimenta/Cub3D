/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:11:53 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/18 18:12:48 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_wall_column_pixel(int x, int y, int wall_height, t_game *cub)
{
	float	wall_start;
	float	wall_end;

	wall_start = (HEIGHT / 2) - wall_height;
	wall_end = (HEIGHT / 2) + wall_height;
	if (y < wall_start)
		return (set_pixel_color(x, y, cub->texture.ceiling, cub));
	if (y >= wall_end)
		return (set_pixel_color(x, y, cub->texture.floor, cub));
}

void	render_wall_column(t_game *cub, int x, float dis)
{
	int	wall_height;
	int	y;

	wall_height = min(HEIGHT / (1.5 * dis), HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		render_wall_column_pixel(x, y, wall_height, cub);
		y++;
	}
	handle_texture(x, wall_height, cub);
}

float	calculate_wall_distance(t_game *cub, float ray_angle)
{
	float	distance;
	float	delta_x;
	float	delta_y;

	cub->ray.cos = cos(degree_to_radians(ray_angle)) / cub->ray.precision;
	cub->ray.sin = sin(degree_to_radians(ray_angle)) / cub->ray.precision;
	cub->ray.x_pos = cub->player.x_pos + 0.5;
	cub->ray.y_pos = cub->player.y_pos + 0.5;
	while (!has_ray_reached_limit(cub))
	{
		cub->ray.x_pos += cub->ray.cos;
		cub->ray.y_pos += cub->ray.sin;
	}
	delta_x = cub->ray.x_pos - cub->player.x_pos - 0.5;
	delta_y = cub->ray.y_pos - cub->player.y_pos - 0.5;
	distance = sqrt(powf(delta_x, 2.) + powf(delta_y, 2.));
	return (distance * cos(degree_to_radians(ray_angle - cub->ray.angle)));
}

void	render_scene(t_game *cub)
{
	float	ray_angle;
	int		ray_count;
	float	distance;

	ray_angle = cub->ray.angle - cub->ray.hfov;
	ray_count = WIDTH - 1;
	while (ray_count >= 0)
	{
		distance = calculate_wall_distance(cub, ray_angle);
		render_wall_column(cub, ray_count, distance);
		ray_angle += cub->ray.increment_angle;
		ray_count--;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->window_image.i, 0, 0);
}