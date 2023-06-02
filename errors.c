/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 00:10:30 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/02 14:11:16 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	my_mlx_destroy(t_img *img, t_game *cub)
{
	if (img && img->i)
		mlx_destroy_image(cub->mlx, img->i);
}

int	close_game(t_game *cub)
{
	my_mlx_destroy(cub->texture.north, cub);
	my_mlx_destroy(cub->texture.south, cub);
	my_mlx_destroy(cub->texture.west, cub);
	my_mlx_destroy(cub->texture.east, cub);
	my_mlx_destroy(cub->texture.black, cub);
	my_mlx_destroy(&cub->window_image, cub);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	free(cub->mlx);
	matrix_free(cub->map.array);
	exit(0);
	return (0);
}

int error_msg(char *msg)
{
	printf("Error: %s\n", msg);
	return (0);
}

int	exit_cub(char *msg, t_game *cub)
{
	if (msg)
		error_msg(msg);
	return (close_game(cub));
}