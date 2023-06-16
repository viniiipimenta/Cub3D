/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:14:08 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/15 23:21:54 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int it_is_xpm(char *img)
{
	int	len;

	len = ft_strlen(img);
	if (ft_strncmp(img + len - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}

t_img	*img_load(char *img, t_game *cub)
{
	t_img	*i;

	i = malloc(sizeof(t_img));
	i->i = NULL;
	if (!img || !it_is_xpm(img) || !check_file(img))
		exit_cub("Try a valid texture", cub);
	i->i = mlx_xpm_file_to_image(cub->mlx, img, &i->width, &i->height);
	if (!i->i)
		exit_cub("xpm file failed", cub);
	i->addr = mlx_get_data_addr(i->i, &i->bpp, &i->line_len, &i->endian);
	return (i);
}