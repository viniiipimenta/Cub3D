/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:02:41 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/23 18:16:28 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_key_down(int key, t_game *cub)
{
	if (key == 119)
		cub->keys.w_pressed = 1;
	if (key == 97)
		cub->keys.a_pressed = 1;
	if (key == 115)
		cub->keys.s_pressed = 1;
	if (key == 100)
		cub->keys.d_pressed = 1;
	if (key == 65361)
		cub->keys.left_pressed = 1;
	if (key == 65363)
		cub->keys.right_pressed = 1;
	if (key == 65307)
		close_cub(cub);
	return (0);
}

int	handle_key_up(int key, t_game *cub)
{
	if (key == 119)
		cub->keys.w_pressed = 0;
	if (key == 97)
		cub->keys.a_pressed = 0;
	if (key == 115)
		cub->keys.s_pressed = 0;
	if (key == 100)
		cub->keys.d_pressed = 0;
	if (key == 65361)
		cub->keys.left_pressed = 0;
	if (key == 65363)
		cub->keys.right_pressed = 0;
	return (0);
}