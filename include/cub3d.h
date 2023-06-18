/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:32:39 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/18 18:22:28 by mpimenta         ###   ########.fr       */
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
# define M_PI 3.14159265358979323846

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
void    map_validation(t_game *cub);
int	is_valid_cell(char map_cell);
int	is_player_cell(char map_cell);
void	check_for_open_wall(char **map, int px, int py, t_game *cub);

//start mlx

void init(t_game *cub);
t_img	*img_load(char *img, t_game *cub);

//Matrix

void	matrix_free(char **matrix);
int	matrix_len(char **matrix);
char	**matrix_push(char **matrix, char *new);
char	**dup_matrix(char **matrix);

//analyze map

void	map_analyze(char *path, t_game *cub);
void	handle_map_line(char *line, t_game *cub);
void	normalize_map(t_game *cub);
int	is_floor(char *key);
int	is_ceiling(char *key);
int	is_color_texture(char *key);
int	is_cardinal_direction(char *key);
int	is_valid_key(char *key);
int	is_duplicate_key(char *key, t_game *cub);
int	is_east(char *key);
int	is_west(char *key);
int	is_south(char *key);
int	is_north(char *key);

//handle

int	handle_key_up(int key, t_game *cub);
int	handle_key_down(int key, t_game *cub);
void	handle_player_move(t_game *cub);
int is_wall(int x, int y, t_game *cub);
float	degree_to_radians(float degree);

//utils

char	*gnl_util(int fd);
void	handle_line(char *line, int count, t_game *cub);
int	count_char_in_string(char *string, char to_find);
int	max(int a, int b);
int	min(int a, int b);

//colors

int	get_color_from_string(char *string, t_game *cub);
void	handle_texture_line(char *line, t_game *cub);

//render 

void	render_scene(t_game *cub);
void	set_pixel_color(int x, int y, int color, t_game *cub);
int	has_ray_reached_limit(t_game *cub);
void	handle_texture(int ray_count, int wall_height, t_game *cub);
unsigned int	get_texture_pixel_color(int x, int y, t_img *img);

#endif