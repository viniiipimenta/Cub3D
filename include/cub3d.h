/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:32:39 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/02 00:27:57 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#ifdef __linux__
#include "../libs/mlx_linux/mlx.h"
#else
#include "../libs/mlx/mlx.h"
#endif

# include "../libs/gnl/get_next_line.h"
# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

typedef struct  s_game
{
    void		*mlx;
	void		*win;
}               t_game;

// validation 

int error_msg(char *msg);
int validation_file(int argc, char **argv);
int check_file(char *map);

#endif