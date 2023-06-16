/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:15:15 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/15 23:27:57 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_raycasting(t_game *cub)
{
	cub->ray.angle = 0;
	cub->ray.cos = 0;
	cub->ray.hfov = 30;
	cub->ray.increment_angle = 2 * cub->ray.hfov / WIDTH;
	cub->ray.limit = 11;
	cub->ray.precision = 50;
	cub->ray.sin = 0;
	cub->ray.x_pos = 0;
	cub->ray.y_pos = 0;
}

void	init_keybord(t_game *cub)
{
	cub->keys.w_pressed = 0;
	cub->keys.a_pressed = 0;
	cub->keys.s_pressed = 0;
	cub->keys.d_pressed = 0;
	cub->keys.left_pressed = 0;
	cub->keys.right_pressed = 0;
}

void	init_texture(t_game *cub)
{
	cub->window_image.i = NULL;
	cub->texture.north = NULL;
	cub->texture.south = NULL;
	cub->texture.east = NULL;
	cub->texture.west = NULL;
	cub->texture.black = NULL;
	cub->texture.floor = -1;
	cub->texture.ceiling = -1;
	cub->texture.black = img_load("texture/black.xpm", cub);
	if (!cub->texture.black || !cub->texture.black->i)
		exit_cub("Try to run from the root of the project", cub);
}

void	init_variables(t_game *cub)
{
	cub->mlx = mlx_init();
	cub->win = NULL;
	cub->map.array = NULL;
	cub->map.height = 0;
	cub->map.width = 0;
	cub->player.dir = 0;
	cub->player.speed = 0.20;
	cub->player.x_pos = -1;
	cub->player.y_pos = -1;
    cub->frame.count = 0;
	cub->frame.rate = 30;
}

void init(t_game *cub)
{
    init_variables(cub);
    init_texture(cub);
    init_keybord(cub);
    init_raycasting(cub);
}