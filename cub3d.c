/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:32:24 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/15 22:54:43 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	initialize_window(t_game *cub)
{
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	cub->window_image.i = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->window_image.addr = mlx_get_data_addr(cub->window_image.i,
			&cub->window_image.bpp, &cub->window_image.line_len,
			&cub->window_image.endian);
}

void	initialize_ray(t_game *cub)
{
	if (cub->player.dir == 'S')
		cub->ray.angle = 0;
	if (cub->player.dir == 'E')
		cub->ray.angle = 90;
	if (cub->player.dir == 'N')
		cub->ray.angle = 180;
	if (cub->player.dir == 'W')
		cub->ray.angle = 270;
}

void	start_mlx(t_game *cub)
{
	initialize_window(cub);
	initialize_ray(cub);
	mlx_hook(cub->win, 2, 1L << 0, handle_key_down, cub);
	mlx_hook(cub->win, 3, 1L << 1, handle_key_up, cub);
	mlx_hook(cub->win, 17, 0, close_cub, cub);
	//mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_loop(cub->mlx);
}

int main(int argc, char **argv)
{
    t_game cub;
    
    if (!validation_file(argc, argv))
        return (0);
    init(&cub);
    map_analyze(argv[1], &cub);
    map_validation(&cub);
    start_mlx(&cub);
    return (0);
}