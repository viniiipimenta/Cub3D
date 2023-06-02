/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:32:39 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/02 14:24:20 by mpimenta         ###   ########.fr       */
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

# define WIDTH 640
# define HEIGHT 480

typedef struct s_img
{
	int		height;
	int		width;
	void	*i;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_texture
{
	t_img	*north;
	t_img	*south;
	t_img	*east;
	t_img	*west;
	t_img	*black;
	int		floor;
	int		ceiling;
}			t_texture;

typedef struct s_player
{
	float	x_pos;
	float	y_pos;
	char	dir;
	float	speed;
}			t_player;

typedef struct s_ray
{
	float	increment_angle;
	float	angle;
	float	cos;
	float	sin;
	float	hfov;
	float	limit;
	int		precision;
	float	x_pos;
	float	y_pos;
}			t_ray;

typedef struct s_pressed
{
	int		w_pressed;
	int		a_pressed;
	int		s_pressed;
	int		d_pressed;
	int		left_pressed;
	int		right_pressed;
}			t_pressed;

typedef struct s_map
{
	char	**array;
	int		width;
	int		height;
}			t_map;

typedef struct s_frame
{
	long	count;
	int		rate;
}			t_frame;

typedef struct  s_game
{
    void		*mlx;
	void		*win;
	t_img		window_image;
	t_map		map;
	t_ray		ray;
	t_pressed	keys;
	t_frame		frame;
	t_player	player;
	t_texture	texture;
}               t_game;

// validation 

int error_msg(char *msg);
int	exit_cub(char *msg, t_game *cub);
int	close_cub(t_game *cub);
int validation_file(int argc, char **argv);
int check_file(char *file);

//start mlx

void init(t_game *cub);
t_img	*img_load(char *img, t_game *cub);

//Matrix

void	matrix_free(char **matrix);

#endif