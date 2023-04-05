/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:20:58 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/04/05 17:37:35 by adegain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../Libft/libft.h"
# include "../srcs/get_next_line/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define CHAR_TITLE		"Totally Spies!"
# define FILE_EXT		".cub"
# define MAP_CHAR		"10NSEW"
# define MAP_PLYR		"NSEW"
# define IMG_LENGTH		64
# define IMG_WIDTH		64
# define W_K			119		// forward
# define S_K			115		// back
# define A_K			97		// left
# define D_K			100		// right
# define ESC_K			65307
# define LEFT_A			65361	// rotate_left
# define RIGHT_A		65363	// rotate_right

# define ERR_ENV		"Error\nUninitialized environment\n"
# define ERR_ARG		"Error\nWrong number of arguments\n"
# define ERR_RD			"Error\nOpen fonction error\n"
# define ERR_EXT		"Error\nWrong file extension (must be .cub)\n"
# define ERR_MAP		"Error\nThe map is incorrect\n"
# define ERR_DEF		"Error\nThe map elements are missing or incorrect\n"
# define ERR_DBL		"Error\nThe map elements are mentionned twice\n"
# define ERR_CLR		"Error\nWrong value in colors parameters\n"
# define ERR_FIL		"Error\nWrong value in images parameters\n"
# define ERR_MALLOC		"Error\nMalloc error\n"
# define ERR_NO_IMG		"Error\nInvalid north image path\n"
# define ERR_SO_IMG		"Error\nInvalid south image path\n"
# define ERR_WE_IMG		"Error\nInvalid west image path\n"
# define ERR_EA_IMG		"Error\nInvalid east image path\n"

typedef enum s_direction
{
	N,
	S,
	E,
	W
}	t_direction;

typedef struct s_elem
{
	char	*no_img;
	char	*so_img;
	char	*we_img;
	char	*ea_img;
	int		floor[3];
	int		cell[3];
	char	floor_hex[3];
	char	cell_hex[3];
	int		flag_floor;
	int		flag_cell;
	int		w;
	int		h;
}	t_elem;

typedef struct s_map
{
	char				**map;
	char				*line;
	int					player_nb;
	int					elem_nb;
	int					map_height;
	int					map_length;
	t_direction			direction;
	t_elem				elem;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
}	t_game;

typedef struct s_img
{
	void	*mlx_img;
	void	*mlx_img2;
	int		*addr;
	int		*addr2;
	int		bpp;
	int		line_len;
	int		endian;
	int		floor;
	int		cell;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
}	t_img;

typedef struct s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
	double		raydir_x;
	double		raydir_y;	
	double		cam_x;
	int 		map_x;
	int			map_y;
	double		sidedist_y;
	double		sidedist_x;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		paperwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int 		x;
	double		time;
	double		movespeed;
	double		rotspeed;
}	t_ray;

typedef struct s_text
{
	int			texdir; 
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
} t_text;

typedef struct s_cub3d
{
	t_map	map;
	t_game	game;
	t_img	img;
	t_ray	ray;
	t_img	texture[5];
	t_text	text;
	char	**file;
	float	screen_width;
	float	screen_height;
	int		sizex;
	int		sizey;
	int		left_key;
	int		right_key;
	int		move;
	int	swap_img;
	
}	t_cub3d;

/******** MAIN ********/

/******** PARSING *****/
// ---- get_file
int		check_cub(char *av);
char	**get_file(char *av, t_cub3d *cub3d);

// ---- init_struct
void	init_elem_struct(t_cub3d *cub3d);

// ---- parsing_elements
int		check_file(t_cub3d *cub3d);

// ---- parsing_args
int		parse_imgs(char *line, t_cub3d *cub3d, int type);
int		parse_color(char *line, t_cub3d *cub3d, int type);

// ---- parsing_map
int		generate_map(char **file, t_cub3d *cub3d);
int		check_map(t_cub3d *cub3d);
int		valid_file(char **file);

// ---- utils
int		valid_char(char c, int flag);
int		char_is_space(char c);
int		height_map(char **file);
int		check_length_map(t_cub3d *cub3d);
char	*ft_strdupdup(t_cub3d *cub3d, char *s);

// ---- free
void	free_struct(t_cub3d *cub3d);
void	print_struct(t_cub3d *cub3d);

/******** GAME ********/
// ---- init_game
int		game(t_cub3d *cub3d);
int		print_map(t_cub3d *cub3d);
void	ray_pos(t_cub3d *cub3d);
void	def_ray(t_cub3d *cub3d);
void 	draw(t_cub3d *cub3d, int x0, int start_wall, int end_wall); 

// ---- init_imgs
int		init_imgs(t_cub3d *cub3d, t_elem *elem);

// ---- move_player
void	move_forward_backward(t_map *map, t_ray *ray, t_cub3d *cub3d);
void	move_left_right(t_map *map, t_ray *ray, t_cub3d *cub3d);
void	rot_left_right(t_ray *ray, t_cub3d *cub3d);
int		move_player(int keycode, t_cub3d *cub3d);
int		release_player(int keycode, t_cub3d *cub3d);

// ---- free_game
void	free_before_exit(t_cub3d *cub3d, int flag);
int		close_btn(t_cub3d *cub3d);
void	free_imgs(t_cub3d *cub3d);
#endif 