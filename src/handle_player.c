/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:56:36 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/18 18:00:11 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	get_angle(int key, t_game *cub)
{
	if (key == 0)
		return (cub->ray.angle + 90);
	if (key == 1)
		return (cub->ray.angle - 180);
	if (key == 2)
		return (cub->ray.angle - 90);
	return (cub->ray.angle);
}

void	update_player_position(float ray_sin, float ray_cos, t_game *cub)
{
	int	new_x;
	int	new_y;
	int	curr_x;
	int	curr_y;

	new_x = cub->player.x_pos + 0.5 + (3 * ray_cos);
	new_y = cub->player.y_pos + 0.5 + (3 * ray_sin);
	curr_x = cub->player.x_pos + 0.5;
	curr_y = cub->player.y_pos + 0.5;
	if (!is_wall(new_x, curr_y, cub))
		cub->player.x_pos += ray_cos;
	if (!is_wall(curr_x, new_y, cub))
		cub->player.y_pos += ray_sin;
}

void	move_player(int key, t_game *cub)
{
	float	angle;
	float	ray_cos;
	float	ray_sin;

	angle = get_angle(key, cub);
	ray_cos = cos(degree_to_radians(angle)) * cub->player.speed;
	ray_sin = sin(degree_to_radians(angle)) * cub->player.speed;
	update_player_position(ray_sin, ray_cos, cub);
}

void	handle_player_move(t_game *cub)
{
	if (cub->keys.left_pressed)
		cub->ray.angle += 3;
	if (cub->keys.right_pressed)
		cub->ray.angle -= 3;
	if (cub->keys.w_pressed)
		move_player(13, cub);
	if (cub->keys.a_pressed)
		move_player(0, cub);
	if (cub->keys.s_pressed)
		move_player(1, cub);
	if (cub->keys.d_pressed)
		move_player(2, cub);
}